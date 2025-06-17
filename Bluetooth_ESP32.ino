
#include "BluetoothSerial.h"
#include <Preferences.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
Preferences preferences;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test");  //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  preferences.begin("Bluet_received", 0);
}

void loop() {
  if (Serial.available()) {
    Serial.write(SerialBT.read());
    char received_data = SerialBT.read();
    Serial.println("Received Data is : ");
    Serial.print(received_data);
  }
  if (SerialBT.available()) {
    char received_data[64];  // Create a character array to store the received data
    int index = 0;           // Initialize an index to keep track of the current position in the array

    while (SerialBT.available()) {
      received_data[index] = SerialBT.read();  // Read the incoming byte from the Bluetooth serial port
      index++;                                 // Move to the next position in the array
    }
    received_data[index] = '\0';  // Add null terminator to mark the end of the string

    Serial.println("Received Data is : ");  // Print the label indicating received data
    Serial.println(received_data);          // Print the received string

    // Save the received data to Preferences
    preferences.putString("receivedData", received_data);
  }
  delay(20);
}