/*
  MorseCode.cpp - Library for talking Morse code
  Created by Thiago Salles
*/

#include "Arduino.h"
#include "MorseCode.h"

MorseSymbol* MorseCode::convertCharToSymbols(char charToConvert) {
	static MorseSymbol* symbols;
	switch (charToConvert) {
		case 'A':
			symbols = new MorseSymbol[2] {DOT, DASH};
		break;
		case 'B':
			symbols = new MorseSymbol[4] {DASH, DOT, DOT, DOT};
		break;
		case 'C':
			symbols = new MorseSymbol[4] {DASH, DOT, DASH, DOT};
		break;
		case 'D':
			symbols = new MorseSymbol[3] {DASH, DOT, DOT};
		break;
		case 'E':
			symbols = new MorseSymbol[1] {DOT};
		break;
		case 'F':
			symbols = new MorseSymbol[4] {DOT, DOT, DASH, DOT};
		break;
		case 'G':
			symbols = new MorseSymbol[3] {DASH, DASH, DOT};
		break;
		case 'H':
			symbols = new MorseSymbol[4] {DOT, DOT, DOT, DOT};
		break;
		case 'I':
			symbols = new MorseSymbol[2] {DOT, DOT};
		break;
		case 'J':
			symbols = new MorseSymbol[4] {DOT, DASH, DASH, DASH};
		break;
		case 'K':
			symbols = new MorseSymbol[3] {DASH, DOT, DASH};
		break;
		case 'L':
			symbols = new MorseSymbol[4] {DOT, DASH, DOT, DOT};
		break;
		case 'M':
			symbols = new MorseSymbol[2] {DASH, DASH};
		break;
		case 'N':
			symbols = new MorseSymbol[2] {DASH, DOT};
		break;
		case 'O':
			symbols = new MorseSymbol[3] {DASH, DASH, DASH};
		break;
		case 'P':
			symbols = new MorseSymbol[4] {DOT, DASH, DASH, DOT};
		break;
		case 'Q':
			symbols = new MorseSymbol[4] {DASH, DASH, DOT, DASH};
		break;
		case 'R':
			symbols = new MorseSymbol[3] {DOT, DASH, DOT};
		break;
		case 'S':
			symbols = new MorseSymbol[3] {DOT, DOT, DOT};
		break;
		case 'T':
			symbols = new MorseSymbol[1] {DASH};
		break;
		case 'U':
			symbols = new MorseSymbol[3] {DOT, DOT, DASH};
		break;
		case 'V':
			symbols = new MorseSymbol[4] {DOT, DOT, DOT, DASH};
		break;
		case 'W':
			symbols = new MorseSymbol[3] {DOT, DASH, DASH};
		break;
		case 'X':
			symbols = new MorseSymbol[4] {DASH, DOT, DOT, DASH};
		break;
		case 'Y':
			symbols = new MorseSymbol[4] {DASH, DOT, DASH, DASH};
		break;
		case 'Z':
			symbols = new MorseSymbol[4] {DASH, DASH, DOT, DOT};
		break;
		case '0':
			symbols = new MorseSymbol[5] {DASH, DASH, DASH, DASH, DASH};
		break;
		case '1':
			symbols = new MorseSymbol[5] {DOT, DASH, DASH, DASH, DASH};
		break;
		case '2':
			symbols = new MorseSymbol[5] {DOT, DOT, DASH, DASH, DASH};
		break;
		case '3':
			symbols = new MorseSymbol[5] {DOT, DOT, DOT, DASH, DASH};
		break;
		case '4':
			symbols = new MorseSymbol[5] {DOT, DOT, DOT, DOT, DASH};
		break;
		case '5':
			symbols = new MorseSymbol[5] {DOT, DOT, DOT, DOT, DOT};
		break;
		case '6':
			symbols = new MorseSymbol[5] {DASH, DOT, DOT, DOT, DOT};
		break;
		case '7':
			symbols = new MorseSymbol[5] {DASH, DASH, DOT, DOT, DOT};
		break;
		case '8':
			symbols = new MorseSymbol[5] {DASH, DASH, DASH, DOT, DOT};
		break;
		case '9':
			symbols = new MorseSymbol[5] {DASH, DASH, DASH, DASH, DOT};
		break;
		case ' ':
			symbols = new MorseSymbol[1] {WORDS_SPACE};
		break;
	}
	// TODO: Include the COMPONENTS_SPACE
	Serial.print("Simbolos: ");
	for (MorseSymbol* symbol = symbols; *symbol != '\0'; *symbol++) {
		Serial.print("[");
		Serial.print(*symbol);
		Serial.print("]");
	}
	Serial.println();
	return symbols;
}

MorseSymbolProperties MorseCode::getProperties(MorseSymbol symbol) {
	switch (symbol) {
		case DOT:
			return {
				voiceOn: true,
				voiceTime: 1
			};
		case DASH:
			return {
				voiceOn: true,
				voiceTime: 3
			};
		case COMPONENTS_SPACE:
			return {
				voiceOn: false,
				voiceTime: 1
			};
		case CHARACTERS_SPACE:
			return {
				voiceOn: false,
				voiceTime: 3
			};
		case WORDS_SPACE:
			return {
				voiceOn: false,
				voiceTime: 7
			};
	}
}
