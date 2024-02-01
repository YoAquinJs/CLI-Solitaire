#include "piles.hpp"

Foundation::Foundation() : CardPile(new std::vector<Card*>()) {}

bool Foundation::CanAddCard(Card* card){
	if (Count() == 0)
		return card->GetRank() == CardRank::ACE;

	return card->GetSuit() == GetAt(0)->GetSuit() && GetAt(0)->IsOneLesserRank(card);
}
