#pragma once

#include <vector>
#include "cardPile.hpp"

class CardColumn : public CardPile {
	private:
		bool CanAddCard(Card* card) override;
		
	public:
		CardColumn(std::vector<Card*> cards);
		bool MoveSubColumn(int index, CardColumn* destination);
};