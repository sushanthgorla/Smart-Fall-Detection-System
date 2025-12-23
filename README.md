# Smart-Fall-Detection-System
Arduino-based fall detection system using MPU6050 sensor, LCD, and buzzer
# Smart Fall Detection System

## Overview
The Smart Fall Detection System is an Arduino-based safety solution designed to detect sudden falls using an MPU6050 accelerometer sensor. When a fall is detected, the system alerts using a buzzer and displays a warning message on an LCD.

## Components Used
- Arduino Uno
- MPU6050 Accelerometer & Gyroscope
- 16x2 LCD Display
- Buzzer
- Jumper Wires
- Breadboard

## Working Principle
The MPU6050 measures acceleration along X, Y, and Z axes. The total acceleration magnitude is calculated and compared with a predefined threshold. If the value falls below the threshold, a fall is detected and an alert is triggered.

## Features
- Real-time fall detection
- Audible alert using buzzer
- LCD status display
- Reliable sensor-based monitoring

## Technologies Used
- Arduino
- Embedded C
- I2C Communication
- MPU6050 Sensor

