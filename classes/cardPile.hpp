#pragma once

#include "card.hpp"
#include <vector>

class CardPile{
	protected:
		std::vector<Card*> cards;
		virtual void AddCard(Card* card);
		virtual bool CanAddCard(Card* card);

	public:
		CardPile(std::vector<Card*> cards) : cards(cards) {}

		bool TryAddCard(Card* card);
		void RemoveLast();
		Card* GetLast();
};