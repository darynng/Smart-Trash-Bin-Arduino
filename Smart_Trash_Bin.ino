#include <Servo.h>

Servo lidServo;
const int trigPin = 7;
const int echoPin = 8;

long duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lidServo.attach(3);       // Servo connected to pin 3
  lidServo.write(90);       // Lid is normally closed
  delay(1000);
  Serial.begin(9600);
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Speed of sound ≈ 0.034 cm/µs, sound travels to object and back.

  // If object is within 5cm → open lid
  if (distance <= 5) {
    lidServo.write(50);     // Open lid
    delay(5000);            // Keep open for 5 seconds
    lidServo.write(90);     // Return to close position
  }

  delay(200);
}
