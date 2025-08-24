# 📡 ESP32 Bluetooth Receiver with Data Storage

This project demonstrates how to use an **ESP32** to receive data over **Bluetooth Serial (SPP)** and store it in **non-volatile memory (NVS)** using the `Preferences` library.

---

## 🛠️ Features

- Connects ESP32 via Bluetooth as a device named `ESP32test`
- Receives data over Bluetooth using `BluetoothSerial`
- Displays received data in the Serial Monitor
- Stores received data in non-volatile memory using `Preferences`
- Data remains available after a restart or power cycle

---

## 🧰 Requirements

- ESP32 development board
- Arduino IDE with ESP32 board support
- Bluetooth-capable device (e.g. smartphone, PC)
- Optional: Bluetooth terminal app (like **Serial Bluetooth Terminal**)

---

## 📦 Libraries Used

- [BluetoothSerial](https://github.com/espressif/arduino-esp32) (Built-in with ESP32 Arduino core)
- Preferences (for non-volatile storage)

---

## 🔌 Setup Instructions

1. **Install ESP32 support in Arduino IDE:**
   - Go to `File > Preferences`, and add this URL under **Additional Board Manager URLs**:
     ```
     https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
     ```
   - Then go to `Tools > Board > Board Manager`, search for **ESP32**, and install it.

2. **Connect your ESP32** board via USB.

3. **Upload the code** to your ESP32.

4. **Pair your Bluetooth device** with ESP32 (device name: `ESP32test`).

5. **Send data** from your device using a Bluetooth terminal app.

---

## 🧪 How It Works

### 🔁 Setup (`setup()` function)

- Initializes serial communication at 115200 baud.
- Starts Bluetooth with the device name `ESP32test`.
- Initializes Preferences storage with namespace `"Bluet_received"`.

### 🔄 Loop (`loop()` function)

- Checks if Bluetooth data is available:
  - Reads the entire incoming message.
  - Displays it on the Serial Monitor.
  - Stores it in non-volatile memory using `preferences.putString("receivedData", ...)`.
- Contains a logic block for Serial-to-Bluetooth echo (may need revision — see Notes).

---

## 💾 Persistent Storage

The data received via Bluetooth is saved with:

```cpp
preferences.putString("receivedData", received_data);
```

You can retrieve it later using:

```
preferences.getString("receivedData");
```
## ⚠️ Notes & Improvements

The block checking Serial.available() incorrectly reads from SerialBT. You can remove or fix it:
```
if (Serial.available()) {
    SerialBT.write(Serial.read());
}
```

Always check SerialBT.available() before reading to avoid reading invalid data.

delay(20) is a basic debounce; consider using millis() or a proper buffer for high-frequency data.

## 🧾 Example Output
The device started, now you can pair it with Bluetooth!
```
Received Data is :
Hello from phone!
```
## 📋 License

This project is released under the MIT License
.

## 🙋‍♂️ Author

Created by ** Shakaib Naqvi ** 
For educational and IoT prototyping purposes.


---

Let me know if you'd like:

- A downloadable `.md` file
- GitHub-style formatting with badges
- Modifications for WiFi instead of Bluetooth
- JSON or CSV logging of received data

I'm happy to help tailor this further.
