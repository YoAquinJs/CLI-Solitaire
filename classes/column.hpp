#pragma once

#include <vector>

#include "cardPile.hpp"

class Column : public CardPile {
	bool CanAddCard(Card* card) override;
		
	public:
		explicit Column(std::vector<Card*>* initialCards);
		
		bool MoveCard(CardPile* destination) override;
		bool MoveSubColumn(int index, Column* destination);
};
