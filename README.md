# DIY_Bluetooth_Rover
# Bluetooth Operated Rover with Arduino Mega

This project involves creating a rover controlled via Bluetooth using an Arduino Mega, L298N motor driver, and an HC-05 Bluetooth module. The rover is equipped with 4 DC motors with gear ratios for movement control. The mobile app for controlling the rover was built using MIT App Inventor.

## Hardware Components

- Arduino Mega
- L298N Motor Driver
- HC-05 Bluetooth Module
- 4 DC Motors with Gear Ratios
- Chassis and Wheels
- Power Supply (Batteries)

## Software

- Arduino IDE (for uploading code to Arduino Mega)
- MIT App Inventor (for creating the mobile app)

## Wiring

- Connect the motor driver pins (EN1, IN1, IN2, EN2, IN3, IN4) to the respective pins on the Arduino Mega.
- pin configurations for Arduino is given in the code file.
- Connect the HC-05 Bluetooth module to the Arduino Mega for communication.

## Functionality

The Arduino code enables the Bluetooth-operated rover to perform the following actions:

- Move forward: 'a' or 'A'
- Move backward: 'b' or 'B'
- Stop: 'c' or 'C'
- Turn left: 'd'
- Turn right: 'e'
- Adjust speed using analog input (0-1023)

## Usage

1. Upload the provided Arduino code to the Arduino Mega.
2. Assemble the hardware components on the rover chassis.
3. Power up the rover using appropriate power sources (batteries).
4. Pair the HC-05 module with your mobile device.
5. Use the mobile app built in MIT App Inventor to send control commands to the rover via Bluetooth.

## Contributors

Yuvraj Singh, Nishit Mittal

