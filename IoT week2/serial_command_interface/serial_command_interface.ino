/*
-------------------------------------------------------
Project      : Serial Command Interface
Author       : Priyanshu Yadav
Roll Number  : 24BCA037
Description  :
Control the built-in LED using commands sent from
the Serial Monitor.
-------------------------------------------------------
*/

const int LED = LED_BUILTIN;

String command = "";
int blinkCounter = 0;
bool ledState = false;

void setup() {

  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  Serial.begin(9600);

  Serial.println("=== Serial Command Interface ===");
  Serial.println("Commands:");
  Serial.println("LED_ON");
  Serial.println("LED_OFF");
  Serial.println("BLINK_X (X = 1-9)");
  Serial.println("STATUS");
  Serial.println("RESET");
}

void loop() {

  if (Serial.available()) {

    command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "LED_ON") {

      digitalWrite(LED, HIGH);
      ledState = true;
      Serial.println("LED ON");

    }

    else if (command == "LED_OFF") {

      digitalWrite(LED, LOW);
      ledState = false;
      Serial.println("LED OFF");

    }

    else if (command.startsWith("BLINK_")) {

      int count = command.substring(6).toInt();

      if (count >= 1 && count <= 9) {

        for (int i = 0; i < count; i++) {

          digitalWrite(LED, HIGH);
          delay(300);

          digitalWrite(LED, LOW);
          delay(300);

        }

        blinkCounter += count;

        Serial.print("LED Blinked ");
        Serial.print(count);
        Serial.println(" times");

      }

      else {

        Serial.println("ERROR: Blink value must be between 1 and 9");

      }

    }

    else if (command == "STATUS") {

      Serial.println("------ STATUS ------");

      Serial.print("LED State : ");

      if (ledState)
        Serial.println("ON");
      else
        Serial.println("OFF");

      Serial.print("Blink Count : ");
      Serial.println(blinkCounter);

      Serial.println("--------------------");

    }

    else if (command == "RESET") {

      blinkCounter = 0;

      Serial.println("Blink Counter Reset");

    }

    else {

      Serial.println("ERROR: Unknown command");

    }

  }

}