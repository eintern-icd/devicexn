#include <Norvi.h>

void setup() {
  Serial.begin(115200);
  
  // Initialize device if required, or remove invalid Norvi.begin() if not supported by this library version.
}

void loop() {
  // Publishing explicitly typed values matching Norvi library prototypes (int, float, bool)
  Norvi.publish("temperature", (int)24);
  //Norvi.publish("humidity", (float)55.5);
  //Norvi.publish("motor_status", (bool)true);
  
  delay(5000); 
}
