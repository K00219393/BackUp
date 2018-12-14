#pragma once
#include "PlayableCharacters.h"

class ShreddyShuerger : public PlayableCharacters
{
public:
	// A constructor specific to ShreddyShuerger
	ShreddyShuerger();

	// The overriden input handler for ShreddyShuerger
	bool virtual handleInput();

};

