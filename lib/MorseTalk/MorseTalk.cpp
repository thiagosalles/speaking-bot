/*
  MorseTalk.cpp - Library for talking Morse code
  Created by Thiago Salles
*/

#include "Arduino.h"
#include "MorseTalk.h"

MorseTalk::MorseTalk(int speakerPin, int mainLedPin, int tiltLedPin) {
  _speakerPin = speakerPin;
  _mainLedPin = mainLedPin;
  _tiltLedPin = tiltLedPin;
  pinMode(_mainLedPin, OUTPUT);
  pinMode(_tiltLedPin, OUTPUT);
  _tilted = false;
  _lastTime = millis();
  _codeToSay = LinkedList<int>();
}

void MorseTalk::process() {

  // If tilted, abort.
  if (_tilted) return;

  _checkLoopInterval();
  _speak();

}

void MorseTalk::_checkLoopInterval() {
  unsigned long _currentTime = millis();
  if (_currentTime - _lastTime > ACCEPTED_DELAY) {
    _tilt();
  }
  _lastTime = _currentTime;
}

void MorseTalk::_tilt() {
  _tilted = true;
  Serial.println("!!! TILT !!!");
  digitalWrite(_tiltLedPin, HIGH);
  _voiceOff();
  // chamar a função de callback em _tiltCallback se existir. Externalizar o LED quando isso estiver pronto
}

void MorseTalk::say(char* text) {

  // Abort if it is already saying something
  if (_codeToSay.size() > 0) return;

  for (char* character = text; *character != '\0'; *character++) {
    Serial.println(*character);
	MorseSymbol* symbols = MorseCode::convertCharToSymbols(*character);
	/*
	for (MorseSymbol* symbol = symbols; *symbol != '\0'; *symbol++) {
		Serial.print(*symbol);
	}
	Serial.println();
	*/
  }

  _codeToSay.add(DOT);
}

void MorseTalk::_speak() {

  // If tilted, abort
  if (_tilted) return;
}

void MorseTalk::_voiceOn() {
  tone(_speakerPin, NOTE_C4);
  digitalWrite(_mainLedPin, HIGH);
}

void MorseTalk::_voiceOff() {
  noTone(_speakerPin);
  digitalWrite(_mainLedPin, LOW);
}
