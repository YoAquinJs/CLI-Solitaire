#pragma once

#include <map>
#include <vector>

#include "direction.hpp"
#include "linkable.hpp"
#include "card.hpp"

class CardPile : public Linkable<CardPile>{
	protected:
		std::vector<Card*>* cards;
		std::map<Direction, CardPile*> surroundingPiles;

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
