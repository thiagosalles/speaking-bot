/*
  MorseTalk.cpp - Library for talking Morse code
  Created by Thiago Salles
*/

#include "Arduino.h"
#include "MorseTalk.h"

MorseTalk::MorseTalk(int speakerPin, int tiltLedPin) {
  _speakerPin = speakerPin;
  _tiltLedPin = tiltLedPin;
  pinMode(_tiltLedPin, OUTPUT);
  _tilted = false;
  _lastTime = millis();
}

void MorseTalk::process() {
  if (!_tilted) {
    _checkTime();
    //tone(_speakerPin, NOTE_C4);
    //noTone(_speakerPin);
  }
}

void MorseTalk::_checkTime() {
  unsigned long _currentTime = millis();
  Serial.print("Time: ");
  Serial.println(_currentTime);
  if (_currentTime - _lastTime > ACCEPTED_DELAY) {
    _tilt();
  }
  _lastTime = _currentTime;
}

void MorseTalk::_tilt() {
  _tilted = true;
  Serial.println("!!! TILT !!!");
  digitalWrite(_tiltLedPin, HIGH);
  // chamar a função de callback em _tiltCallback se existir. Externalizar o LED quando isso estiver pronto
}
