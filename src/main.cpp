#include <Arduino.h>
#include <LiquidCrystal.h>

// RGB LED pins
const int redPin = 10;
const int greenPin = 9;
const int bluePin = 6;

// Photocell pin
const int photoPin = A0; 

int lightLevel = 0; // stores analog reading

// Thresholds 
const int lowThreshold = 200;
const int highThreshold = 800;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  pinMode(photoPin, INPUT);

  Serial.begin(9600); // for debugging
}

void loop() {
  // Read the light level
  lightLevel = analogRead(photoPin);
  Serial.println(lightLevel);

  // Reset all LEDs
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);

  // Check the light level and turn on the corresponding LED
  if (lightLevel < lowThreshold) {
    digitalWrite(redPin, HIGH); // LOW light
  } 
  else if (lightLevel >= lowThreshold && lightLevel <= highThreshold) {
    digitalWrite(greenPin, HIGH); // NORMAL light
  } 
  else {
    digitalWrite(bluePin, HIGH); // HIGH light
  }

  delay(500); // update twice per second
}

