# MatrixMap
A simple implementation of a Self Driving vehicle code named "WHEEL-E"

## Hardware requirements
1. A small car chassis(We used a RC toy car)
2. Arduino Uno or equivalent
3. L239D motor driver IC
4. DC motors
5. HC-05 Bluetooth module
6. SR-04 Ultrasonic sensor
7. Wires
8. PCB or a breadboard

## Software requirements
1. Android Studio
2. Arduino Genuino

## Circuit Diagram
https://drive.google.com/open?id=0B7Vej6y2bVHobUxxZmFRY2xfcElYTXJfbmlUaFktOG1SMW5N

## How it works
A map (We've used a graph represented as 2D matrix) of a given region is stored in the app. A source node and destination node are chosen. Using a simple recursion algorithm, a path to the destination is generated. This route data is transferred to the car via bluetooth. The car then travels along the path while sensing for obstacles like people or other objects. If any obstacles are detected, the waits until it is removed. This process of detect-and-wait repeats till it reaches its destination.
