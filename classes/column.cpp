#include <algorithm>

#include "piles.hpp"

Column::Column(std::vector<Card*>* initialCards) : CardPile(initialCards) {
	for (int i = 1; i < cards->size(); i++) {
		GetAt(i)->hidden = true;
	}
	GetAt(0)->hidden = false;
}

bool Column::CanAddCard(Card* card) {
	if (Count() == 0)
		return card->GetRank() == CardRank::KING;
	return card->IsOneLesserRank(GetAt(0)) && card->IsDiffColor(GetAt(0));
}

bool Column::MoveCard(CardPile* destination){
	if (Count() == 0 || !(destination->TryAddCard(GetAt(0))))
		return false;

	cards->erase(cards->begin());
	
	if (GetAt(0) != nullptr)
		GetAt(0)->hidden = false;
	return true;
}

bool Column::MoveSubColumn(int index, Column* destination){
	if (Count() == 0 || GetAt(index)->hidden || !destination->CanAddCard(GetAt(index)))
		return false;

	for (int i = index; i > -1; i--){
		destination->AddCard(GetAt(i));
		cards->erase(cards->begin() + i);
	}

	if (GetAt(0) != nullptr)
		GetAt(0)->hidden = false;
	return true;
}
