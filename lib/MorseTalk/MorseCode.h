/*
  MorseCode.h - Library for talking Morse code
  Created by Thiago Salles
*/

#ifndef MorseCode_h
#define MorseCode_h

#include "Arduino.h"

enum MorseSymbol {
	DOT = 0,
	DASH = 1,
	COMPONENTS_SPACE = 2,
	CHARACTERS_SPACE = 3,
	WORDS_SPACE = 4
};

struct MorseSymbolProperties {
	bool voiceOn;
	int voiceTime;
};

class MorseCode {

  public:

	static MorseSymbol* convertCharToSymbols(char charToConvert);
	static MorseSymbolProperties getProperties(MorseSymbol symbol);

};

#endif
