#pragma once

#include <string>

enum class CardSuit { SPADES, HEARTS, CLUBS, DIAMONDS };
enum class CardRank { ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

class Card{
	CardSuit suit;
	CardRank rank;

	public:
		bool hidden;

		Card(CardSuit suit, CardRank rank);

		CardSuit GetSuit();
		CardRank GetRank();
		char SuitToChar();
		std::string RankToStr();
		bool IsLesserRank(Card* card);
		bool IsDiffColor(Card* card);
};
