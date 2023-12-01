#pragma once

#include <vector>
#include "card.hpp"

class CardPile{
	protected:
		std::vector<Card*>* cards;
		virtual void AddCard(Card* card);
		virtual bool CanAddCard(Card* card);

	public:
		CardPile(std::vector<Card*>* initialCards);
		~CardPile();

		int Count();
		Card* GetAt(unsigned int index);
		bool TryAddCard(Card* card);
		virtual bool MoveCard(CardPile* destination);
};