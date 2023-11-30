#pragma once

#include <vector>
#include "cardPile.hpp"

class Foundation : public CardPile {
	private:
		bool CanAddCard(Card* card) override;
	public:
		Foundation();
};