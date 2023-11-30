#pragma once

#include "card.hpp"
#include <vector>

class CardPile{
	protected:
		std::vector<Card*> cards;
		virtual void AddCard(Card* card);
		virtual bool CanAddCard(Card* card);

	public:
		CardPile(std::vector<Card*> cards);

		int Count();
		bool TryAddCard(Card* card);
		Card* GetAt(unsigned int index);
		virtual bool MoveCard(CardPile* destination);
};