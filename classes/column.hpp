#pragma once

#include "cardPile.hpp"

class CardColumn : public CardPile {
	private:
		bool CanAddCard(Card* card) override;
		
	public:
		using CardPile::CardPile;
		bool MoveSubColumn(int index, CardColumn* destination);
};