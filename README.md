# Bodenfeuchte Sensor mit einem ESP12 (Wifi/Wlan)

Dieser Sensor ist noch in Bearbeitung. Es soll dazu dienen, die Bodenfeuchte von Pflanzen zu messen und per WLan an einen Server zur Datenauswertung zu senden. Für das Sender per Wlan wird ein ESP8266 Modul verwendet. Als Sensor kommt eine kapazitive Messmethode zum Einsatz. Das  Grundgerüst des Sensors basiert auf den [Gies-O-Mat von Fred Ram][1].

## Stromquelle

ALs Stromquelle soll ein 18650 AKku dienen, da dieser über hohe Kapazitäten verfügen kann. So kann eine lange Lebensdauer pro Batterie gewährleistet werden. Es wird davon ausgegangen, dass der Sensor bei halbstündiger Messung bis zu 3 Monate arbeiten kann. (Dies muss noch bewiesen werden)

## Board-Layout

Das Layout wurde mit [Eagle 7.6][2] erstellt.



## bisherige Part-Liste

Part       Value          Device     Package  Library        Sheet

1RX-2TX                   PINHD-1X2  1X02     pinhead        1
13,3V-2GND                PINHD-1X2  1X02     pinhead        1
C1         1000µF         CP-SV-E/F  SV-E/F   cap-master     1
C2         10µF           C1206      1206     capsmd         1
C4         10µF           C1206      1206     capsmd         1
ESP                       ESP12      ESP12    esp8266modules 1
GND                       PINHD-1X1  1X01     pinhead        1
IC1        74HC14D        74HC14D    SO14     74xx-eu        1
IC2        HT7333         HT7333     SOT-89   holtek2        1
PAD1                      2,54/1,0   2,54/1,0 wirepad        1
PAD2                      2,54/1,0   2,54/1,0 wirepad        1
PROG       DTSM-6         DTSM-6     DTSM-6   switch-tact    1
R2         ca 100k        R-EU_R0603 R0603    rcl            1
R3         100            R-EU_R0603 R0603    rcl            1
RESET      DTSM-6         DTSM-6     DTSM-6   switch-tact    1
VIN                       PINHD-1X1  1X01     pinhead        1

## Contribute?

Du möchtest mithelfen, dass Design oder die Software zu verbessern? Dann schreib mir oder sende ein Request.



[1]: https://www.mikrocontroller.net/topic/335407
[2]: https://cadsoft.io/de/