#pragma once

#include <vector>
#include "cardPile.hpp"

class Foundation : public CardPile {
	bool CanAddCard(Card* card) override;
	
	public:
		Foundation();
};
