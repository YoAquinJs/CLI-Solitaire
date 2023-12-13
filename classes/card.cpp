#include "card.hpp"

Card::Card(CardSuit suit, CardRank rank) : suit(suit), rank(rank), hidden(false) {}

CardSuit Card::GetSuit(){
	return suit;
}

CardRank Card::GetRank(){
	return rank;
}

char Card::SuitToChar(){
	switch (suit){
		case CardSuit::CLUBS:
			return 'C';
			break;
		case CardSuit::HEARTS:
			return 'H';
			break;
		case CardSuit::DIAMONDS:
			return 'D';
			break;
		case CardSuit::SPADES:
			return 'S';
			break;
		default:
			return '\n';
			break;
	}
}
std::string Card::RankToStr(){
	switch (rank){
		case CardRank::ACE:
			return " A";
			break;
		case CardRank::JACK:
			return " J";
			break;
		case CardRank::QUEEN:
			return " Q";
			break;
		case CardRank::KING:
			return " K";
			break;
		case CardRank::TEN:
			return "10";
			break;
		default:
			int rank = static_cast<int>(this->rank);
			return "0"+std::to_string(rank);
			break;
	}}

bool Card::IsLesserRank(Card* card){
	return static_cast<int>(rank) < static_cast<int>(card->rank);
}

bool Card::IsDiffColor(Card* card){
	if (suit == CardSuit::HEARTS || suit == CardSuit::DIAMONDS)
		return (card->suit == CardSuit::SPADES || card->suit == CardSuit::CLUBS);
	else
		return (card->suit == CardSuit::HEARTS || card->suit == CardSuit::DIAMONDS);
}