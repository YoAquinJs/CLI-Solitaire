#pragma once

#include <vector>
#include "cardPile.hpp"

class Deck{
	Card** cards;
	
	int deckSize;
	int fetchedCards;

	void swap (Card *a, Card *b);

	public:
		Deck();
		~Deck();

		void Shuffle();
		std::vector<Card*>* GetRange(int fetchedCards);
};
