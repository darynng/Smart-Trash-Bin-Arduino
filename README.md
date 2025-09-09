# Smart-Trash-Bin-Arduino
Smart Trash Bin using Arduino Uno. 
As of 5/1/2024 - Current functionality: Ultrasonic sensor + servo motor automatically opens/closes lid when user approaches. 

## Components

Ultrasonic Sensor (HC-SR04) → Detects user’s hand/object.

Servo Motor (SG90) → Controls lid movement.

Arduino Uno + IDE

## Logic

Sensor measures distance using ultrasonic pulses.

If object detected within ~5 cm → servo rotates lid open (30°).

Otherwise → lid closes (90°).

setup() ensures the lid always resets to 90° at startup.

## Key Notes

Servo angle range: 0–180° (no negatives).

Initial position set in setup() with servo.write(90)
