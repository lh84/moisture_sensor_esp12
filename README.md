V 0.9

# Bodenfeuchte Sensor mit einem ESP12 (Wifi/Wlan)

Dieser Sensor ist noch in Bearbeitung. Es soll dazu dienen, die Bodenfeuchte von Pflanzen zu messen und per WLan an einen Server zur Datenauswertung zu senden. Für das Sender per Wlan wird ein ESP8266 Modul verwendet. Als Sensor kommt eine kapazitive Messmethode zum Einsatz. Das  Grundgerüst des Sensors basiert auf den [Gies-O-Mat von Fred Ram]<sup>[1]</sup>.

## Stromquelle

Als Stromquelle soll ein 18650 Akku dienen, da dieser über hohe Kapazitäten verfügen kann. So kann eine lange Lebensdauer pro Batterie gewährleistet werden. Es wird davon ausgegangen, dass der Sensor bei halbstündiger Messung bis zu 3 Monate arbeiten kann. (Dies muss noch bewiesen werden)

## Board-Layout

Layout was made with Eagle 7.7<sup>[2]</sup>.

![Board](https://raw.githubusercontent.com/lh84/moisture_sensor_esp12/master/images/sensor.png)

First try to model a case for the board in 3d
![Board 3d](https://github.com/lh84/moisture_sensor_esp12/blob/master/export/ecad-io%20.png?raw=true) 

GPIO5 is now used to control vin in smitt trigger to use less power when sensor is not measuring.

## Part-List

see ![bom.txt](https://github.com/lh84/moisture_sensor_esp12/blob/master/bom.txt) 

## Software

As software you can use the source code von Zentris<sup>[3]</sup>. It works pretty good.

## Testing

First test at 20/01/17 was pretty good with this new designed board.

## Prototypes

I made a first prototype of the new design with etching at home. Looks und works pretty good for the first test.
![Board 3d](https://github.com/lh84/moisture_sensor_esp12/blob/master/images/first-prototype.jpg?raw=true) 
![Board 3d](https://github.com/lh84/moisture_sensor_esp12/blob/master/images/first-prototype2.jpg?raw=true) 
![Board 3d](https://github.com/lh84/moisture_sensor_esp12/blob/master/images/first-prototype3.jpg?raw=true) 


## Contribute?

Du hast eine Idee, wie dieser Sensor besser gestaltet werden kann? Dann schreib mir oder sende ein Request.

## TODO

- [ ] Model case for board (fusion 360)
- [ ] check runtime with 18650 battry
- [x] check hardware (first prototype)
- [ ] test hardware in outdoor environment
- [X] produce platines (first prototype)

[1]: https://www.mikrocontroller.net/topic/335407
[2]: https://cadsoft.io/de/
[3]: https://github.com/Zentris/erdfeuchtemessung