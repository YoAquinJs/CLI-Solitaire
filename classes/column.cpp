#include <algorithm>
#include "column.hpp"
#include "../magic_enum/magic_enum.hpp"

bool CardColumn::CanAddCard(Card* card) {
	return card->IsLesserRank(GetIndex(0)) && card->IsDiffColor(GetIndex(0));
}

bool CardColumn::MoveSubColumn(int index, CardColumn* destination){
	if (!destination->CanAddCard(GetIndex(index))){
		return false;
	}

    for (int i = index; i > -1; i--){
		destination->AddCard(GetIndex(i));
		cards.erase(cards.begin() + i);
	}

	return true;
}