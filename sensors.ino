// Include libraries for sensors
#include "DS18B20.h"
#include "pH100A.h"
#include "SEN0189.h"

// Initialize sensors and specify pin numbers
DS18B20 tempSensor(12);
pH100A phSensor(A0);
SEN0189 nitrateSensor(A1);

void setup() {
  // Set up serial communication
  Serial.begin(9600);
}

void loop() {
  // Read values from sensors
  float temp = tempSensor.readTemperature();
  float ph = phSensor.readpH();
  float nitrates = nitrateSensor.readNitrates();

  // Convert values to desired units
  temp = (temp * 1.8) + 32;  // Convert to degrees Fahrenheit
  ph = ph * 10;  // Convert to pH units
  nitrates = nitrates / 1000;  // Convert to ppm

  // Print values to serial monitor
  Serial.print("Water temperature: ");
  Serial.print(temp);
  Serial.println(" F");
  Serial.print("Water pH: ");
  Serial.print(ph);
  Serial.println(" pH");
  Serial.print("Nitrate levels: ");
  Serial.print(nitrates);
  Serial.println(" ppm");

  // Wait a few seconds before taking another reading
  delay(5000);
}
