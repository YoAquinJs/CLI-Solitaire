#include <algorithm>
#include "column.hpp"
#include "../magic_enum/magic_enum.hpp"

CardColumn::CardColumn(std::vector<Card*> cards) : CardPile(cards) {
	for (int i = 1; i < this->cards.size(); i++) {
		GetAt(i)->hidden = true;
    }
}

bool CardColumn::CanAddCard(Card* card) {
	if (Count() == 0)
		return card->GetRank() == CardRank::KING;
	return card->IsLesserRank(GetAt(0)) && card->IsDiffColor(GetAt(0));
}

bool CardColumn::MoveSubColumn(int index, CardColumn* destination){
	if (!destination->CanAddCard(GetAt(index))){
		return false;
	}

    for (int i = index; i > -1; i--){
		destination->AddCard(GetAt(i));
		cards.erase(cards.begin() + i);
	}

	return true;
}