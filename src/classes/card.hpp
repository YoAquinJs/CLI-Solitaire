#pragma once

#include <string>
#include <map>
#include <vector>

#include "linkable.hpp"

const int suitSize = 4;
const int rankSize = 13;
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
		
		bool IsOneLesserRank(const Card* card);
		bool IsDiffColor(const Card* card);
};

class CardPile : public Linkable<CardPile>{
	protected:
		std::vector<Card*>* cards;
		std::map<Direction, CardPile*> surroundingPiles;

		virtual void AddCard(Card* card);
		virtual bool CanAddCard(Card* card);

	public:
		explicit CardPile(std::vector<Card*>* initialCards);
		~CardPile();

		int Count();
		Card* GetAt(int index);
		
		bool TryAddCard(Card* card);
		virtual bool MoveCard(CardPile* destination);
};
