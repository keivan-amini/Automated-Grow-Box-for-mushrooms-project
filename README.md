# Automated GrowBox for mushrooms project
## Overview
The aim of this project is to implement an automated grow box for mushrooms using **Arduino**. The original idea has been designed by a collaboration between [PLAM Creative Studio](https://www.plamstudio.eu/) and [Phylor](https://www.phylor.it/), for the [PoliPolo](https://www.plamstudio.eu/polipolo/) Fab Lab, in which the grow box has been exposed from the 29<sup>th</sup> of April 2022 in the Laboratorio Aperto di Ferrara.

I used this opportunity not only to gain experience but also to develop a project for the Electronics for Applied Physics' course in the University of Bologna. 

After some hours of work, this was final result:

<p align="center">
  <img src="https://github.com/keivan-amini/Automated-Grow-Box-for-mushrooms-project/blob/main/final_growbox_image.jpg?raw=true" align="centre" height="400" width="400" alt="Grow Box"/>
</p>


Pretty cool, isn't it? :heart_eyes:

To download the slides of the project in order to have a global overview you can click [here](https://github.com/keivan-amini/Automated-Grow-Box-for-mushrooms-project/raw/main/Automated%20GrowBox%20for%20Mushrooms%20-%20PDF.pdf).

## Tools required for the project
* Arduino UNO
* Breadbord, resistors, jumper wires
* DHT11 sensor 
* LCD display
* 4-channel Relay
* 4 led grow lights
* Ultrasonic atomiser
* Fan (optional: potentiometer)
* Heat mat
* 4,7 KΩ resistor
* Power strip

Of course if you haven't it yet, you will need to install Arduino Software; detailed instructions for installation in popular operating systems can be found [here](https://github.com/arduino/Arduino).

## What to do
### Electronics

First of all, you will need to connect the sensors to the Arduino UNO. The [DHT 11](https://www.mouser.com/datasheet/2/758/DHT11-Technical-Data-Sheet-Translated-Version-1143054.pdf) sensor allows us to measure the temperature and the humidity of an environment and it is composed by 4 pins as you can see in the following picture:

<p align="center">
  <img src="https://github.com/keivan-amini/Automated-Grow-Box-for-mushrooms-project/blob/main/sensorr-removebg-preview.png?raw=true" align="centre" height="200" width="200" alt="Grow Box"/>
</p>

Where the meaning of the different pins is given by:
* **VCC**: 3.5V to 5.5V;
* **DATA**: outputs both temperature and humidity through serial data;
* **NC**: no connection (not used);
* **GROUND**: connected to the ground of the circuit.

As an example of the electronic connections you could just copy the electronics of the following picture, *but be careful: in the software implementation the pins connected are not the same!* Eventually, just remember to look and change some small parts of the main code.

<p align="center">
  <img src="https://github.com/keivan-amini/Automated-Grow-Box-for-mushrooms-project/blob/main/untitled_s_wZeH3bKRx2-removebg-preview.png?raw=true" align="centre"  alt="Grow Box"/>
</p>

In the next step we have to connect the LCD display. We used an 20x4 character display with an onboard potentiometer which controls the brightness of the display. Altough we used a breadbord, an illustrative image of the connection is given by:

<p align="center">
  <img src="https://github.com/keivan-amini/Automated-Grow-Box-for-mushrooms-project/blob/main/fritzing-sketch-for-lcd1602-and-arduino_VNXIWTehlV-removebg-preview.png?raw=true" align="centre"  alt="Grow Box"/>
</p>

Often when we have to deal with displays in electronics, it is way more confortable to use libraries instead of coding everything by-hand. For this reason we implemeted the LCD display by using a library called `LiquidCrystal_I2C.h` for which you can install it from this simple [repository](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library). For the same reason we have used another library for the [DHT11](https://github.com/adidax/dht11).

It is now time to consider the relay: an important tools when we have to deal with normal voltage electronics. We have used a 4-channel relay for which we have two different side:

**High voltage side**
* NO: Normally Open
* COM: Common
* NC: Normally Closed

**Low voltage side**
* GND
* IN1: Atomiser
* IN2: Fan
* IN3: Light
* IN4: Heat mat
* VCC

We actually used Normally Open connections. That means, when we tell Arduino to output an HIGH signal the current will not flow. Otherwise, when we tell Arduino to output a LOW signal, the current will flow. I personally recommend this [guide](https://randomnerdtutorials.com/guide-for-relay-module-with-arduino/) for those who did not understand how a relay works.
