#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Buttons
const int playBtn = 6;
const int nextBtn = 7;
const int prevBtn = 8;

// LEDs
const int leds[] = {9, 10, A0, A1, A2};

// Volume Potentiometer
const int volumePot = A3;

// Buzzer
const int buzzer = 13;

// Songs
String songs[] = {
  "Ghode 3",
  "Rao Sahab Retro",
  "Total",
  "Weapon",
  "Desi Hood"
};

int currentSong = 0;
bool playing = false;


// Melody Function

void playMelody(int notes[], int size) {
  for (int i = 0; i < size; i++) {

    tone(buzzer, notes[i], 180);

    digitalWrite(leds[i % 5], HIGH);
    delay(150);
    digitalWrite(leds[i % 5], LOW);

    delay(40);

    if (!playing)
      break;
  }

  noTone(buzzer);
}


// Setup

void setup() {

  lcd.begin(16, 2);

  pinMode(playBtn, INPUT_PULLUP);
  pinMode(nextBtn, INPUT_PULLUP);
  pinMode(prevBtn, INPUT_PULLUP);

  pinMode(buzzer, OUTPUT);

  for (int i = 0; i < 5; i++)
    pinMode(leds[i], OUTPUT);

  lcd.print("YT Music");
  lcd.setCursor(0, 1);
  lcd.print("Loading...");

  // Startup Melody
  tone(buzzer, 523, 150);
  delay(180);

  tone(buzzer, 659, 150);
  delay(180);

  tone(buzzer, 784, 150);
  delay(180);

  tone(buzzer, 1047, 250);
  delay(300);

  noTone(buzzer);

  lcd.clear();
}


// Loop

void loop() {

  // PLAY / PAUSE
  if (digitalRead(playBtn) == LOW) {

    playing = !playing;

    if (playing)
      tone(buzzer, 900, 120);
    else
      tone(buzzer, 500, 120);

    delay(300);
  }

  // NEXT
  if (digitalRead(nextBtn) == LOW) {

    currentSong++;

    if (currentSong > 4)
      currentSong = 0;

    tone(buzzer, 1200, 80);
    delay(90);
    tone(buzzer, 1500, 80);

    delay(300);
  }

  // PREVIOUS
  if (digitalRead(prevBtn) == LOW) {

    currentSong--;

    if (currentSong < 0)
      currentSong = 4;

    tone(buzzer, 1500, 80);
    delay(90);
    tone(buzzer, 1200, 80);

    delay(300);
  }

  // Volume
  int volume = map(analogRead(volumePot), 0, 1023, 0, 100);

  // LCD Display
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print(songs[currentSong]);

  lcd.setCursor(0, 1);

  if (playing)
    lcd.print("Play ");
  else
    lcd.print("Pause");

  lcd.print(" V:");
  lcd.print(volume);
  lcd.print("%");

  // Song Melodies
  if (playing) {

    switch (currentSong) {

      case 0: {
          int notes[] = {523, 659, 784, 880, 784};
          //playMelody(notes, 5);
          break;
        }

      case 1: {
          int notes[] = {784, 698, 659, 587, 523};
          //playMelody(notes, 5);
          break;
        }

      case 2: {
          int notes[] = {523, 587, 659, 587, 523};
          //playMelody(notes, 5);
          break;
        }

      case 3: {
          int notes[] = {659, 784, 880, 784, 659};
          //playMelody(notes, 5);
          break;
        }

      case 4: {
          int notes[] = {784, 880, 988, 880, 784};
          //playMelody(notes, 5);
          break;
        }

    }
    
    for(int i = 0; i < 5; i++)
    digitalWrite(leds[i], random(0,2));
    delay(80);

  } else {

    noTone(buzzer);

    for (int i = 0; i < 5; i++)
      digitalWrite(leds[i], LOW);

    delay(100);
  }
}