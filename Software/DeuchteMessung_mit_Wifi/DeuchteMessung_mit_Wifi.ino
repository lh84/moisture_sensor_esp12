// ------------------------------------
// Erdfeuchtemessung mit ESP8266-01
// ---
// Measure soil moisture with ESP8266-01
// (the source code variables and so on is original writen in german,
// a translation will be come later if necessary)
//
// @Autors:
//       - Ralf Wießner (aka Zentris)
//       - code for ntp adopted from Michael Margolis
//       - code for time_ntp adopted from by Stefan Thesen
//
// @Known_bugs:
//       -- none --
//
// @Open_issues:
//       - switching time stamp to MESZ and back
//       - use MAC for ESP identifiyer
//       - watchdog signal (get a blinking LED)
//       - translate variables to english
//       - translate comments to english
//
// @Feature_and_History:
//   1.0 :
//       - setting the measurement intervals via HTTP request answer
//       - 2 measurment canals (GPIO0 and GPIO2)
//       - data transfer to local data server
//       - data transfer to remote Thingsspeak server (optional)
//       - 10 probs on each measurement loop
//       - create median and create the mean value over 5 media values
//       - use a local timeserver (here a fritzbox)
//         (adoption of time_ntp)
// ------------------------------------

#define versionnumber "1.0"

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>

#include <WiFiClient.h>

#include <DNSServer.h>
#include <WiFiManager.h>        //https://github.com/tzapu/WiFiManager

//#define DEBUGPRINT
#ifdef DEBUGPRINT
#define DEBUG_PRINT(x)  Serial.println (x)
#else
#define DEBUG_PRINT(x)
#endif
// led to indicate sending data
#define LED 12
// define the GPIO
#define INTPIN 4
// all times in milliSec
#define MESSABSTAND_DEFAULT 30000
#define messzeitms           1000
#define messintervalle         10
#define ntpRefreshAfter   3600000
// HTTP request codes
#define HTTP_CODE_OK 200

unsigned int sleedTime        = 1 * (60 * 1000 * 1000); // == 30 Minuten
unsigned long messabstand     = MESSABSTAND_DEFAULT;  // default = 30sec
unsigned long ntpdRefreshTime = 0;                    // Zeitpunkt, wann die Zeit erneut geholt wird

//SimpleTimer timer;

String clientName;
WiFiClient wifiClient;

const char* host = "api.thingspeak.com";
//https://api.thingspeak.com/update?api_key=EQUNYB3NUC9GHS1K&field1=2.33
//either define key here of create a config.h key and add it there
const char* privateKey = "KWSOPYZFUZTS9F9N";

volatile unsigned long counter = 0;   // interrupt loop counter
unsigned long bodenfeuchteGemittelt;  //

ADC_MODE(ADC_VCC);

int vcc;
long startMills;
void sendData();

void setup(void)
{
  pinMode(LED, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  //ESP.eraseConfig();
  startMills = millis();
  // start serial port
  Serial.begin(115200);
  //-------------------
  DEBUG_PRINT();
  WiFiManager wifi;
  //wifi.resetSettings();
  //WiFiManager wifiManager;
  //wifiManager.autoConnect("esp-lars-1", "123456");
  wifi.setTimeout(120); // so if it restarts and router is not yet online, it keeps rebooting and retrying to connect
  if (!wifi.autoConnect("layv", "7e%f52%wxh%txr8@")) {
    DEBUG_PRINT("timeout - going to sleep");
    DEBUG_PRINT(millis() - startMills);
    delay(200);
    ESP.deepSleep(sleedTime); // sleep for 30 min and try again
    delay(200);
  }
  DEBUG_PRINT(millis() - startMills);
  //-------
  //setup hardware

}

/**
   Einfache Median/Mittelwertberechnung
   ------------------------------------
   Übergebenes Array sortieren und über die im Array "in der Mitte" liegenden
   Werte den Durchschnitt ermitteln.
   @todo: translate
*/
unsigned long median(unsigned long *values, int arraySize) {
  unsigned long tmp;
  const int relVal = 2;  // +- 2 Werte + 1 für die Mittelwertberechnung

  for (int i = 0; i < arraySize; i++) {
    for (int j = arraySize - 1; j > i; j--) {
      if ( values[j] < values[j - 1] ) {
        tmp = values[j];
        values[j] = values[j - 1];
        values[j - 1] = tmp;
      }
    }
  }
  for (int i = arraySize / 2 - relVal; i < arraySize / 2 + relVal; tmp += values[i++]) {}
  return tmp / (relVal * 2 + 1);
}

/**
   Interrupt function: increment the counter
*/
void intfunc() {
  counter++;
}

/**
   Feuchtemessung per Frequenzmessung + Messwertglättung
*/
void bodenfeuchtemessung(int gpioPin) {
  unsigned long speicherArray[messintervalle];

  for (int i = 0; i < messintervalle; i++) {
    Serial.print("Messung Nr.: "); Serial.print(i);
    Serial.print(" an GPIO-Pin "); Serial.print(gpioPin);
    Serial.print(" = ");
    counter = 0;
    //  attachInterrupt(gpioPin, intfunc, CHANGE);
    attachInterrupt(gpioPin, intfunc, RISING);
    delay(messzeitms);
    detachInterrupt(gpioPin);
    speicherArray[i] = counter;
    Serial.println(counter);
  }
  bodenfeuchteGemittelt = median(speicherArray, messintervalle);
  Serial.print("Gemittelt: "); Serial.println(bodenfeuchteGemittelt);
  //  writeWebLog("[bodenfeuchtemessung:010] Median=" + String(bodenfeuchteGemittelt));
}

/**
   ThingsSpeak: https://api.thingspeak.com/update?api_key=<--yourKey-->&field1=0
*/
void saveData2ThingsSpeak()
{
  digitalWrite(LED, LOW);
  digitalWrite(LED, HIGH);

  String channel_124665_key = "KWSOPYZFUZTS9F9N";
  String channel_124422_key = "EQUNYB3NUC9GHS1K";
  String tsServer = "api.thingspeak.com";
  String tsServerSIP = "184.106.153.149";  // statische Addresse!
  String tsAPIKey = channel_124422_key;

  Serial.println("Try to send to ThingsSpeak...");
  Serial.println("Try to get REST request: ");
  String request = "/update?api_key=" + tsAPIKey +
                   "&field2=" + String(bodenfeuchteGemittelt) +
                   "&field1=" + ESP.getVcc();
  Serial.println(request);

  HTTPClient http;
  http.begin(tsServerSIP.c_str(), 80, request);
  int httpCode = http.GET();
  if (httpCode) {
    // HTTP header has been send and Server response header has been handled
    Serial.printf("[HTTP] GET... code: %d\n", httpCode);
    // don't found at server
    if (httpCode != 200) {
      Serial.print("[HTTP] GET... failed, no connection or no HTTP server\n");
      Serial.println(http.getString());
    }
    else Serial.println("[HTTP] GET... successfull");
  }
  digitalWrite(LED, LOW);
}

void loop(void)
{
  DEBUG_PRINT(millis() - startMills);
  //read twice as the first result is cached from last time. suggested by @chaeplin
  delay(2000);
  // saveData2ThingsSpeak();
  DEBUG_PRINT(millis() - startMills);

  unsigned long looptimeStart = millis();

  Serial.println("\n--START-MESSUNG--");
  bodenfeuchtemessung(INTPIN); // Sensor GPIO 4
  //saveData2ThingsSpeak();    // currently not active, optional
  Serial.print("messabstand       = "); Serial.println(messabstand);

  unsigned long looptimeEnde = millis();           // whole loope time without delay
  unsigned long looptime = looptimeEnde - looptimeStart;

  Serial.print("looptime          = "); Serial.println(looptimeEnde - looptimeStart);
  Serial.print("messabstand (neu) = "); Serial.println(messabstand - looptime);
  //String s = "Nächste Messung: " + getDatum() + " :: " + getTime() + "\n";
  //Serial.printf(String("Nächste Messung: " + getDatum() + " :: " + getTime() + "\n").c_str());

  delay(messabstand - looptime);

  delay(250);
  digitalWrite(LED, LOW);
  ESP.deepSleep(sleedTime); //
  delay(1000);
}
