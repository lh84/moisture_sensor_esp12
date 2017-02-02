REV 1.0

# Moisture Sensor with an ESP8266 12F (Wifi/Wlan)

This project is still work in progress!

This sensor is intended to measure the soil moisture of plants and to send them by WIFI to a server for data evaluation. An ESP8266 module is used for the sender to send data over the air. A capacitive measuring method is used as a sensor to get moisture values. The basic framework of the sensor is based on the [Gies-O-Mat von Fred Ram]<sup>[1]</sup>.

## power source

A 18650 battery is to be used as power source, as this can have high capacities. A long life per battery can be guaranteed. It is assumed that the sensor can operate for up to 3 months at half-hour measurement - This must still be proven!

## Board-Layout

Layout was made with Eagle 7.7<sup>[2]</sup>.

![Board](https://raw.githubusercontent.com/lh84/moisture_sensor_esp12/master/images/v1/sensor.png)

First try to model a case for the board in 3d
<img src="https://github.com/lh84/moisture_sensor_esp12/blob/master/export/ecad-io%20.png?raw=true" width="250">

GPIO5 is now used to control Vin in smitt trigger to use less power when sensor is not measuring.

## Part-List

| Qty | Value           | Device      | Package     | Parts               | Description                              | Price per pc     | Order-Link                                                                                                                                             | 
|-----|-----------------|-------------|-------------|---------------------|------------------------------------------|------------|--------------------------------------------------------------------------------------------------------------------------------------------------| 
| 2   | PINHD-1X2       | 1X02        | 1RX-2TX     | 3,3V-2GND           | PIN HEADER                               | 0,28 € (0,71 € / 10pc) | https://www.reichelt.de/Buchsenleisten/MPE-115-1-010/3/index.html?ACTION=3&LA=2&ARTICLE=119955&GROUPID=7435&artnr=MPE+115-1-010&SEARCH=%252A     | 
| 1   | 100Ω             |  R-EU_R0603 | R0603       | R3                  | RESISTOR, European symbol                | 0,02 €   | https://www.reichelt.de/SMD-0603-von-0-bis-910-Ohm/RND-0603-1-100/3/index.html?ACTION=3&LA=5&ARTICLE=183013&GROUPID=7967&artnr=RND+0603+1+100    | 
| 1   | 1000µF          | CP-SV-E/F   | SV-E/F      | C1                  |  Big POLARIZED CAP                       | 0,32 €  | https://www.reichelt.de/Elkos-SMD-Low-ESR-105-C/VF-1000-6-3-P-F/3/index.html?ACTION=3&LA=5&ARTICLE=109181&GROUPID=4001&artnr=VF+1000%2F6%2C3+P-F | 
| 2   | 10µF            | C1206       | 1206        | C2, C4              | Small SMD Cap                            | 0,07 €   | https://www.reichelt.de/Vielschicht-SMD-G1206/X7R-G1206-10-16/3/index.html?ACTION=3&LA=5&ARTICLE=89740&GROUPID=8049&artnr=X7R-G1206+10%2F16      | 
| 1   | 500KΩ            | R-TRIMM3374 | R-TRIMM3374 | R1TRIM              | Trimm resistor til 500KΩ                 | 0,67 €  | https://www.reichelt.de/Miniaturtrimmer/23B-500K/3/index.html?ACTION=3&GROUPID=3131&ARTICLE=146090&OFFSET=16&                                    | 
| 1   | 74HC14D 74HC14D | SO14        | IC1         | Hex schmitt trigger | INVERTER                                 | 0,18 €  | https://www.reichelt.de/ICs-74HC-SMD/SMD-HC-14/3/index.html?ACTION=3&GROUPID=2931&ARTICLE=18640&SEARCH=74HC14&OFFSET=16&                         | 
| 2   | DTSM-6  DTSM-6  | DTSM-6      | PROG, RESET |                     | Push button                              | 0,24 €  | https://www.reichelt.de/Kurzhubtaster/TASTER-9314/3/index.html?ACTION=3&GROUPID=7587&ARTICLE=44510&OFFSET=500&                                   | 
| 1   | ESP12           | ESP12       | ESP12       | ESP                 | ESP8266 Wifi module 12                   | 2,54 €  | https://www.aliexpress.com/item/1-pcs-x-ESP-12F-ESP8266-ESP-12F-Remote-Serial-Port-WIFI-Transceiver-Wireless-Module-UNO/32581210212.html         | 
| 1   | HT7333          | HT7333      | SOT-89      | IC2                 | Step Down Module (Ultra low current 4µA) | 0,12 € (1,18€ / 10pc) | https://www.aliexpress.com/item/10PCS-HT7333-A-SOT89-HT7333-1-SOT-89-HT7333A-1-7333-1-SMD-7333A-1-new/32531141419.html                           | 
| 2   | LSP11           | LSP11       | LSP11       | LSP1, LSP2          | SOLDER PAD                               | no costs   |                                                                                                                                                  | 
| 1   | Platine         | EPCU        |             |                     | Size 200X100, one side copper            | 0,58 € (1,75 €) | https://www.reichelt.de/Platinenzuschnitte/EPCU-200X100/3/index.html?ACTION=3&LA=2&ARTICLE=7408&GROUPID=7783&artnr=EPCU+200X100&SEARCH=%252A     |
| 1 | Accu 18650       |         |             |                     | e.g. LG ICR18650S3 - 2200mAh, 3,6 - 3,7V Lithium Ionen Akku | 3,95 € | https://www.akkuteile.de/lg-icr18650s3-2200mah/a-100629 |
| 1 |  18650 Holder     |         |             |                     | | 0,44 € | https://de.aliexpress.com/item/Hot-With-Wire-Lead-Plastic-18650-Battery-3-7V-Clip-Holder-Storage-Box-Case-Cheap-Sale/32458234409.html |
||
|**Sum**||||||**10,00€ + shipping + work**||


Reichelt Order List: https://www.reichelt.de/my/1310317

see also file https://github.com/lh84/moisture_sensor_esp12/blob/master/bom.txt

## Software

As software you can use the source code von Zentris<sup>[3]</sup>. Version 2.2 works pretty good with some small changes.

## Testing

First test at 20/01/17 was pretty good with this new designed board.

## Prototypes

I made a first prototype of the new design with etching at home. Looks und works pretty good for the first test.

<img src="https://github.com/lh84/moisture_sensor_esp12/blob/master/images/v1/first-prototype3.jpg?raw=true" width="250">
<img src="https://github.com/lh84/moisture_sensor_esp12/blob/master/images/v1/sensor_in_soil.jpeg?raw=true" width="250">
<img src="https://github.com/lh84/moisture_sensor_esp12/blob/master/images/v1/first-prototype.jpg?raw=true" width="250">
<img src="https://github.com/lh84/moisture_sensor_esp12/blob/master/images/v1/first-prototype2.jpg?raw=true" width="250">

## First tests with prototype

You can see the live data from my first sensor prototype monitored in thingspeak:
https://thingspeak.com/channels/210863/charts/1?width=1000&height=600&bgcolor=%23ffffff&color=%23d62020&results=240&type=line&update=15&timescale=240


## Contribute?

You have an idea how this sensor can be designed better? Then write me or send a request.

## TODO
- [ ] Model case for board (fusion 360)
- [ ] Add battery monitoring with voltage devider (http://www.esp8266-projects.com/2015/03/internal-adc-esp8266.html)

## In Progress
- [ ] check runtime with 18650 battry
- [ ] test hardware in outdoor environment

## Done
- [x] build first prototype
- [x] check hardware (first prototype)


[1]: https://www.mikrocontroller.net/topic/335407
[2]: https://cadsoft.io/de/
[3]: https://github.com/Zentris/erdfeuchtemessung
