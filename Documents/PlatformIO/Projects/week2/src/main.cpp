#include <Arduino.h>

// Define analog pins
#define ANALOG_PIN_1 1 // GPIO1
#define ANALOG_PIN_2 2 // GPIO2

// put function declarations here:
int myFunction(int, int);

void setup() {
  // Initialize serial monitor
  Serial.begin(115200);

  // Configure ADC resolution to 12 bits
  analogReadResolution(12);
  
  // Set reference voltage to 3.3V
  analogSetAttenuation(ADC_0db); // Default reference voltage is 3.3V, no extra setup needed
}

void loop() {
  // Read analog values from GPIO1 and GPIO2
  int rawValue1 = analogRead(ANALOG_PIN_1);
  int rawValue2 = analogRead(ANALOG_PIN_2);

  // Convert raw values to voltages
  float voltage1 = (rawValue1 / 4095.0) * 3.3; // 12-bit resolution, max value is 2^12 - 1 = 4095
  float voltage2 = (rawValue2 / 4095.0) * 3.3;

  // Print results to the serial monitor
  Serial.print("GPIO1 Voltage: ");
  Serial.print(voltage1, 3); // Keep 3 decimal places
  Serial.print(" V, GPIO2 Voltage: ");
  Serial.print(voltage2, 3); // Keep 3 decimal places
  Serial.println(" V");


  // Delay for 1 second
  delay(1000);
}