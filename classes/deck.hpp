#pragma once

#include "cardPile.hpp"

class Deck{
	private:
		int deckSize;
		Card** cards;

		void swap (Card *a, Card *b);

	public:
		Deck();
		~Deck();

		void Shuffle();
		CardPile* GetRange(int start, int count);
};