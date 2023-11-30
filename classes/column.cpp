#include <algorithm>
#include "column.hpp"
#include "../magic_enum/magic_enum.hpp"

bool CardColumn::CanAddCard(Card* card) {
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