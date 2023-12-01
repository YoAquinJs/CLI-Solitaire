#pragma once

#include <vector>
#include "cardPile.hpp"

class Deck{
	int deckSize;
	int fetchedCards;
	Card** cards;

	void swap (Card *a, Card *b);

	public:
		Deck();
		~Deck();

		void Shuffle();
		std::vector<Card*>* GetRange(int fetchedCards);
};