#pragma once

#include "cardPile.hpp"
#include "direction.hpp"
#include "section.hpp"

class Cursor{
	private:
		Section* section;
		unsigned int pileIndex;
		unsigned int cardIndex;
	
	public:
		Cursor(Section* section);
		
		bool locked;
		void Move(Direction direction);
		CardPile* GetPile();
		Card* GetCard();
};