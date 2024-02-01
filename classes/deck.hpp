#pragma once

#include <vector>

#include "card.hpp"

class Deck{
	Card** cards;

	int deckSize;
	int fetchedCards;

	void swap (Card *a, Card *b);

	public:
		Deck();
		~Deck();

		void Shuffle();
		
		int GetSize();
		std::vector<Card*>* GetRange(int fetchedCards);
};
