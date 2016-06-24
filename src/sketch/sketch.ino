/*
	Speaking Robot
*/

#include <MorseTalk.h>

// Output numbers for the amplifier
#define MIN_ANALOG_OUTPUT 127
#define MAX_ANALOG_OUTPUT 255

// Digital Pins
#define RIGHT_SPEAKER_PIN 2
#define MORSE_LED_PIN 4
#define TILT_LED_PIN 3
// Analog Pins
#define AMPLIFIER_PIN 7
#define POT_PIN 6

// Stores the potentiometer value
int potVal = 0;

MorseTalk morseTalk(RIGHT_SPEAKER_PIN, MORSE_LED_PIN, TILT_LED_PIN);

// the setup routine runs once when you press reset:
void setup() {
  // Open the serial port at 9600 bps
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {

  // Reading the potentiometer
  potVal = analogRead(POT_PIN);
  //Serial.print("Value to use as amplifier input (Volume): ");
  //Serial.println(outputBasedOnPot(potVal));

  morseTalk.process();
  delay(millis()/100); // a cada 1s serão 10ms de delay. 10s para 100ms que faz o tilt
}

float potMultiplier(int potVal) {
  return potVal / 1023.0;
}

int outputBasedOnPot(int potVal) {
  int outputDiff = MAX_ANALOG_OUTPUT - MIN_ANALOG_OUTPUT;
  return MIN_ANALOG_OUTPUT + outputDiff * potMultiplier(potVal);
}

