/*
  Speaking Robot
*/

#include <MorseTalk.h>

// Digital Pins
#define RIGHT_SPEAKER_PIN 2
#define MORSE_LED_PIN 4
#define TILT_LED_PIN 3
#define BUTTON_PIN 5

int buttonState = 0;

MorseTalk morseTalk(RIGHT_SPEAKER_PIN, MORSE_LED_PIN, TILT_LED_PIN);

// the setup routine runs once when you press reset:
void setup() {
  // Open the serial port at 9600 bps
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  morseTalk.process();

  buttonState = digitalRead(BUTTON_PIN);
  if (buttonState == HIGH) {
    morseTalk.voiceOn();
  } else {
    morseTalk.voiceOff();
  }
}

