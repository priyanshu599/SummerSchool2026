# LED Blink using Arduino

## Project Overview

This project demonstrates the basic LED Blink program using an Arduino UNO. The built-in LED connected to digital pin 13 blinks continuously. In the later versions, Serial Monitor support, potentiometer-based speed control, and proper code documentation were added.

---

## Hardware Required

- Arduino UNO
- USB Cable
- Breadboard
- LED (optional)
- 220Ω Resistor (if using an external LED)
- Potentiometer (10kΩ)
- Jumper Wires

---

## Circuit Diagram (Text Description)

### LED Connection

Arduino Pin 13 ----> LED (+)

LED (-) ----> 220Ω Resistor ----> GND

### Potentiometer Connection

Left Pin  ----> 5V

Middle Pin ----> A0

Right Pin ----> GND

---

## How to Upload the Code

1. Connect the Arduino UNO to the computer using a USB cable.
2. Open the Arduino IDE.
3. Open the `led_blink.ino` file.
4. Select **Tools → Board → Arduino UNO**.
5. Select the correct COM Port.
6. Click **Verify** to compile the code.
7. Click **Upload** to upload the program.
8. Open the Serial Monitor to view the blink count and delay value.

---

## Expected Output

- The built-in LED blinks continuously.
- Blink speed changes when the potentiometer is rotated.
- Serial Monitor displays:
  - Blink Count
  - Delay Time

---

## Troubleshooting Tips

1. Ensure the correct COM Port is selected.
2. Verify that the correct Arduino board is selected.
3. Check all jumper wire connections.
4. Make sure the potentiometer is connected to A0.
5. If the code fails to upload, press the Reset button on the Arduino and try again.

---

## Author

**Priyanshu Yadav**

Roll No: **24BCA037**

IIT Jammu Summer School 2026