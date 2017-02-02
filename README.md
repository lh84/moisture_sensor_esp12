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

see in file: https://github.com/lh84/moisture_sensor_esp12/blob/master/bom.txt

## Software

As software you can use the source code von Zentris<sup>[3]</sup>. Version 2.2 works pretty good with some small changes.

## Testing

First test at 20/01/17 was pretty good with this new designed board.

## Prototypes

I made a first prototype of the new design with etching at home. Looks und works pretty good for the first test.

<img src="https://github.com/lh84/moisture_sensor_esp12/blob/master/images/v1/first-prototype.jpg?raw=true" width="250">
<img src="https://github.com/lh84/moisture_sensor_esp12/blob/master/images/v1/first-prototype2.jpg?raw=true" width="250">
<img src="https://github.com/lh84/moisture_sensor_esp12/blob/master/images/v1/first-prototype3.jpg?raw=true" width="250">
<img src="https://github.com/lh84/moisture_sensor_esp12/blob/master/images/v1/sensor_in_soil.jpeg?raw=true" width="250">

## First tests with prototype

You can see the live data from my first sensor prototype monitored in thingspeak:
https://thingspeak.com/channels/210863/charts/1?width=1000&height=600&bgcolor=%23ffffff&color=%23d62020&results=240&type=line&update=15&timescale=240


## Contribute?

You have an idea how this sensor can be designed better? Then write me or send a request.

## TODO

- [ ] Model case for board (fusion 360)
- [ ] check runtime with 18650 battry
- [x] check hardware (first prototype)
- [ ] test hardware in outdoor environment
- [X] produce platines (first prototype)

[1]: https://www.mikrocontroller.net/topic/335407
[2]: https://cadsoft.io/de/
[3]: https://github.com/Zentris/erdfeuchtemessung
