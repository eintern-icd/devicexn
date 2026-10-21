#include <Norvi.h>
#include <ModbusMaster.h>

#define RS485_RXD 16
#define RS485_TXD 15

ModbusMaster node;

void setup() {
  // XY-MD02 standard Modbus baud rate is 9600
  Serial2.begin(115200, SERIAL_8N1, RS485_RXD, RS485_TXD);
  
  // Initialize Modbus slave ID 1 (default for XY-MD02)
  node.begin(1, Serial2);
}

void loop() {
  // Read Input Registers from XY-MD02 (Address 0x0001 = Temperature, 0x0002 = Humidity)
  uint8_t result = node.readInputRegisters(0x0001, 2);

  if (result == node.ku8MBSuccess) {
    float temperature = node.getResponseBuffer(0) / 10.0;
    float humidity = node.getResponseBuffer(1) / 10.0;

    char tempStr[10];
    char humStr[10];
    snprintf(tempStr, sizeof(tempStr), "%.1f", temperature);
    snprintf(humStr, sizeof(humStr), "%.1f", humidity);

    Norvi.publish("temperature", tempStr);
    Norvi.publish("humidity", humStr);
  }

  delay(5000);
}