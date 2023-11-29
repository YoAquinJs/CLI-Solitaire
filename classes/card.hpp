#pragma once

enum class CardSuit;
enum class CardRank;

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