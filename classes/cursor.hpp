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

		Cursor(Section* section);
		
		int GetIndex();
		Card* GetCard();
		CardPile* GetPile();
		Section* GetSection();
		void Move(Direction direction);
};