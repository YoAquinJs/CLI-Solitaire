#pragma once

#include <vector>

#include "cardPile.hpp"

class DrawPile : public CardPile {
	bool CanAddCard(Card* card) override;

	public:
		explicit DrawPile(std::vector<Card*>* initialCards);

		void InitPile();
		bool MoveCard(CardPile* destination) override;
};
