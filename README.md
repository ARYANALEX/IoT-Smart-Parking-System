# 🚗 Automatic Car Parking System using Arduino

This project is an **automated car parking system** that uses **IR sensors**, **servo motors**, and an **I2C LCD** to detect vehicle presence and control parking gates. It tracks the occupancy status of 6 parking slots and visually displays availability while managing entry and exit through motorized gates.

---

## 📦 Components Used

- Arduino Uno (or compatible board)  
- 6 × IR sensors (for each parking slot)  
- 2 × IR sensors (for entry and exit detection)  
- 2 × Servo motors (entry and exit gate control)  
- I2C 16x2 LCD display  
- Jumper wires, breadboard, power supply

---

## ⚙️ Features

- Displays available parking slots in real-time.
- Detects parked cars using IR sensors.
- Automatically opens/closes entry and exit gates using servo motors.
- Displays status both on **LCD** and **Serial Monitor**.
- Prevents entry when parking is full.

---

## 🧠 How It Works

1. **Slot Monitoring**:  
   - IR sensors check the presence of cars in 6 parking slots.  
   - Each sensor state (S1–S6) is updated continuously.

2. **LCD Display**:  
   - Top row shows available slots or “Parking Full” message.  
   - Bottom row displays individual slot statuses (E: Empty, F: Full).

3. **Gate Control**:  
   - If a car is detected at the entry (`ir_enter`) and space is available, entry gate opens automatically.  
   - If a car is detected at the exit (`ir_back`), exit gate opens automatically.  
   - Gates close after a short delay.

---

## 🖥️ Circuit Overview

| Pin       | Connected To      |
|-----------|-------------------|
| D2        | IR Sensor - Entry |
| D4        | IR Sensor - Exit  |
| D5–D10    | IR Sensors S1–S6  |
| D3        | Servo Motor - Entry Gate |
| D11       | Servo Motor - Exit Gate |
| A4, A5    | I2C SDA, SCL for LCD |

---

## 📜 Dependencies

Include the following libraries:

```cpp
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
```

Install `LiquidCrystal_I2C` library via the Arduino Library Manager if not already installed.

---

## 💡 Example Output

### LCD:
```
Slots: 4
S1:E S2:F S3:F
```

### Serial Monitor:
```
Available Slots: 4
S1: E  S2: F  S3: F
S4: E  S5: E  S6: F
```

---

## 🔧 Setup Instructions

1. Connect IR sensors to the respective pins.
2. Connect servo motors to digital pins D3 and D11.
3. Connect the I2C LCD to A4 (SDA) and A5 (SCL).
4. Upload the sketch to your Arduino board.
5. Open the Serial Monitor at 9600 baud to see live updates.

---

## 🧪 Future Improvements

- Integrate RFID for authorized access.
- Add mobile app/Bluetooth interface for live monitoring.
- Use EEPROM to store parking status during power loss.

---

## 📄 License

Open-source project under the [MIT License](LICENSE).
