#pragma once

#include "card.hpp"
#include <vector>

class CardPile{
	protected:
		virtual void AddCard(Card* card);

	public:
		std::vector<Card*> cards;
		CardPile(std::vector<Card*> cards);

		virtual bool CanAddCard(Card* card);
		bool TryAddCard(Card* card);
		void RemoveLast();
		Card* GetIndex(unsigned int index);
};