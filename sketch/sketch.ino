//#include <Norvi.h>

#define RS485_RXD 16
#define RS485_TXD 15

void setup() {
  Serial.begin(115200);
  
  // Initialize Serial2 for RS485 communication
  Serial2.begin(115200, SERIAL_8N1, RS485_RXD, RS485_TXD);
}

void loop() {
  // Transmit test message over RS485
  Serial2.println("RS485 01 SUCCESS");

  // Read incoming bytes from the RS485 bus and echo to Serial Monitor
  while (Serial2.available()) {
    char c = Serial2.read();
    Serial.write(c);
  }

  // Publish a test value via Norvi.publish
  //Norvi.publish("temperature", "25.0");

  delay(5000);
}
