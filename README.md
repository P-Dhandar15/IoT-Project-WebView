# Smart Pumping System
## Smart Pumping System - A Smart Solution to Automize the Manual Pumping Process

This project mainly focuses on the IoT based solution for automation of the overhead water tank filling system in our residential area. 
In this project two Esp8266 MCU connected to the same cloud channel are used, one will be at the Water Source side and other will be at Overhead Tank side. 
The Ultrasonic Sensor connected to the Esp8266 senses the water level in the tank, 
if the Water level is low the Esp8266 will sent the Motor ON signal to the ThingSpeak IoT Cloud and the Esp8266 at the river or dam side is also connected to the same cloud channel will read that signal and turn the ‘Motor ON’. 
If the tank is full the Esp8266 sends the ‘Motor OFF signal’ over the cloud and the other microcontroller at the river/dam side will turn OFF the motor. 
A web interface displaying graphs and indicators is also provided for the user to study and analyze the data from the system.

**Scan the QR to visit the dashboard:**
![image](https://github.com/P-Dhandar15/IoT-Project-WebView/assets/130864863/6555f057-4f3e-46f1-8a8c-8ccaf4714c88=25x25)

We have also publised research paper on this project at **International Journal of Membrane Science and Technology**, you may visit the site and download the paper to know further.
https://cosmosscholars.com/phms/index.php/ijmst/article/view/2815
