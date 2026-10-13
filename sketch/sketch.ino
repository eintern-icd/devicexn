#include <Norvi.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Publishing an integer value
  Norvi.publish("temperature", 24);
  
  // Publishing a float value (note the 'f' at the end)
  Norvi.publish("humidity", 55.5f);
  
  // Publishing a boolean value
  Norvi.publish("motor_status", true);
  
  // Wait 5 seconds before publishing again
  delay(5000); 
}