#pragma once

#include "direction.hpp"
#include "cardPile.hpp"
#include "section.hpp"

class Cursor{
	Section* section;
	unsigned int pileIndex;
	unsigned int cardIndex;
	
	public:
		bool locked;
		int index;

		Cursor(Section* section, int index);
		
		CardPile* GetPile();
		Card* GetCard();
		void Move(Direction direction);
};