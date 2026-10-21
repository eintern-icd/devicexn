#define RS485_RXD 16
#define RS485_TXD 15

Serial2.begin(115200, SERIAL_8N1, RS485_RXD, RS485_TXD);

Serial2.println("RS485 01 SUCCESS");

while (Serial2.available()) {
  char c = Serial2.read();
  Serial.write(c);
}
