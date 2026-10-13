#include <Norvi.h>

void setup() {
  Serial.begin(115200);
  
  // Initialize the Norvi device (assuming standard initialization)
  Norvi.begin(); 
}

void loop() {
  // Publishing an integer value[cite: 1]
  Norvi.publish("temperature", 24);
  
  // Publishing a float value[cite: 1]
  Norvi.publish("humidity", 55.5);
  
  // Publishing a boolean value[cite: 1]
  Norvi.publish("motor_status", true);
  
  // Wait 5 seconds before publishing again
  delay(5000); 
}