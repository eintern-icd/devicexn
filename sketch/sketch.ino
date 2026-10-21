#include <Norvi.h>

void setup() {
  Serial.begin(115200);
  
  // Initialize device if required, or remove invalid Norvi.begin() if not supported by this library version.
}

void loop() {
  
  Norvi.publish("temperature", String("24"));
  Norvi.publish("humidity", String("60"));
  delay(5000); 
}