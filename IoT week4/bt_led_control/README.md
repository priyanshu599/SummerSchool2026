# ESP32 Bluetooth LED Controller

## Description

This project controls LEDs over Bluetooth using the ESP32's built-in Bluetooth Classic.

## Commands

- R → Red LED ON
- G → Green LED ON
- B → Blue LED ON
- X → All LEDs OFF
- F → Flash LEDs five times

## Pairing

1. Upload the code to ESP32.
2. Enable Bluetooth on your Android phone.
3. Pair with **ESP32_LED**.
4. Open the **Serial Bluetooth Terminal** app.
5. Send the commands listed above.

No external HC-05 module is required because ESP32 provides built-in Bluetooth.