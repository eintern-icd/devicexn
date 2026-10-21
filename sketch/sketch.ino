#include <Norvi.h>
#include <ModbusMaster.h>

// Norvi X CPU-ESPS3-X1 onboard RS-485 pins
#define RX_PIN 16
#define TX_PIN 15

ModbusMaster node;

void setup() {
  // Initialize Serial2 for RS-485 communication with XY-MD02
  Serial2.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);
  
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