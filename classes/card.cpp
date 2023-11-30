#include "card.hpp"

Card::Card(CardSuit suit, CardRank rank) : suit(suit), rank(rank), hidden(false) {}

CardSuit Card::GetSuit(){
	return suit;
}

CardRank Card::GetRank(){
	return rank;
}

bool Card::IsLesserRank(Card* card){
	return static_cast<int>(rank) < static_cast<int>(card->rank);
}

bool Card::IsDiffColor(Card* card){
	if (suit == CardSuit::HEARTS || suit == CardSuit::DIAMONDS)
		return (card->suit == CardSuit::SPADES || card->suit == CardSuit::CLUBS);
	else
		return (card->suit == CardSuit::HEARTS || card->suit == CardSuit::DIAMONDS);
}