#pragma once

#include <vector>

#include "card.hpp"

class Column : public CardPile {
	bool CanAddCard(Card* card) override;
		
	public:
		explicit Column(std::vector<Card*>* initialCards);
		
		bool MoveCard(CardPile* destination) override;
		bool MoveSubColumn(int index, Column* destination);
};

class Foundation : public CardPile {
	bool CanAddCard(Card* card) override;

	public:
		Foundation();
};

class DrawPile : public CardPile {
	bool CanAddCard(Card* card) override;

	public:
		explicit DrawPile(std::vector<Card*>* initialCards);

		void InitPile();
		bool MoveCard(CardPile* destination) override;
};
