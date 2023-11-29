#pragma once

#include <iostream>

enum class CardSuit { SPADES, HEARTS, DIAMONDS, CLUBS };
enum class CardRank { ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

class Card{
	private:
		CardSuit suit;
		CardRank rank;

	public:
		bool hidden;
		
		Card(CardSuit suit, CardRank rank);

		CardSuit GetSuit();
		CardRank GetRank();
		bool IsLesserRank(Card* card);
		bool IsDiffColor(Card* card);
};
