#pragma once

#include <vector>
#include "cardPile.hpp"

class DrawPile : public CardPile {
	private:
		bool CanAddCard(Card* card) override;
	public:
		DrawPile(std::vector<Card*> cards);
		bool MoveCard(CardPile* destination) override;

};