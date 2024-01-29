#pragma once

#include <functional>

#include "direction.hpp"
#include "cardPile.hpp"
#include "section.hpp"

class Cursor{
	CardPile* pile;
	Section* section;
	unsigned int cardIndex;

	public:
		bool locked;

		Cursor(Section* section , int pileIndex);
		
		int GetIndex();
		Card* GetCard();
		CardPile* GetPile();
		Section* GetSection();
		
		void SetIndexToZero();
		void Move(Direction direction, std::function<Section* (CardPile*)> getSection);
};
