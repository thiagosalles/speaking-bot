/*
  MorseTalk.h - Library for talking Morse code
  Created by Thiago Salles
*/

#ifndef MorseTalk_h
#define MorseTalk_h

#define ACCEPTED_DELAY 100

#include "Arduino.h"
#include "MorseCode.h"
#include "LinkedList.h"
#include "pitches.h"

class MorseTalk {

  public:

    MorseTalk(int speakerPin, int mainLedPin, int tiltLedPin);
    void process();
	void say(char* text);
    //void setTiltCallback(tiltCallback); // setar a função de callback quando der algum "tilt"

  private:

    // Pins
    int _speakerPin;
    int _mainLedPin;
    int _tiltLedPin;

	// Tilt Control
    unsigned long _lastTime; // Armazenará o tempo do último processamento, será usado para controlar se o loop da aplicação está muito alto
    void _checkLoopInterval(); // Verificará se o tempo desde a última execução foi muito alto, ficará responsável por atualizar _lastTime
    // _tiltCallback; // Armazenar uma função que vou chamar caso tenha alguma coisa fora do esperado
    boolean _tilted; // Se tiver dado "tilt", armazena nessa variável e interrompe o processamento
    void _tilt(); // Interrompe a execução do MorseTalk, coloca um log de erro e chama o _tiltCallback caso senha sido setado

	// Speaking Control
	LinkedList<int> _codeToSay;
	void _speak();
	void _voiceOn();
	void _voiceOff();
};

#endif
