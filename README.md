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

First of all, you will need to connect the sensors to the Arduino UNO. The [DHT 11](https://www.mouser.com/datasheet/2/758/DHT11-Technical-Data-Sheet-Translated-Version-1143054.pdf) sensor allows us to measure the temperature and the humidity of an environment; it is composed by 4 pins as you can see in the following picture.

