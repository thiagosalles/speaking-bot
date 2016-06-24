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
}

void MorseTalk::process() {
  if (!_tilted) {
    _checkTime();
    if (_hasVoice) {
      tone(_speakerPin, NOTE_C3);
      digitalWrite(_mainLedPin, HIGH);
    } else {
      noTone(_speakerPin);
      digitalWrite(_mainLedPin, LOW);
    }
  }
}

void MorseTalk::voiceOn() {
  _hasVoice = true;
}

void MorseTalk::voiceOff() {
  _hasVoice = false;
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
