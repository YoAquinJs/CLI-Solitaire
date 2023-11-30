#pragma once

#include <vector>
#include "cardPile.hpp"

class Column : public CardPile {
	private:
		bool CanAddCard(Card* card) override;
		
	public:
		Column(std::vector<Card*> cards);
		bool MoveSubColumn(int index, Column* destination);
};