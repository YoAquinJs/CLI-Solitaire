#include <vector>
#include "foundation.hpp"

Foundation::Foundation() : CardPile(std::vector<Card*>()) {}

bool Foundation::CanAddCard(Card* card){
	if (Count() == 0)
		return card->GetRank() == CardRank::ACE;
	return !card->IsDiffColor(GetAt(0)) && GetAt(0)->IsLesserRank(card);
}