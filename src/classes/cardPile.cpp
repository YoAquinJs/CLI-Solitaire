#include <vector>

#include "card.hpp"

CardPile::CardPile(std::vector<Card*>* initialCards) : cards(initialCards), surroundingPiles(std::map<Direction, CardPile*>()) {}

CardPile::~CardPile(){
	delete cards;
}

void CardPile::AddCard(Card* card){
	cards->insert(cards->begin(), card);
}

bool CardPile::CanAddCard(Card* card){
	return true;
}

int CardPile::Count(){
	return cards->size();
}

Card* CardPile::GetAt(int index){
	if (index >= Count() || index < 0)
		return nullptr;
	return cards->at(index);
}

bool CardPile::TryAddCard(Card* card){
	if (!CanAddCard(card))
		return false;
	
	AddCard(card);
	return true;
}

bool CardPile::MoveCard(CardPile* destination){
	if (Count() == 0 || !(destination->TryAddCard(GetAt(0))))
		return false;

	cards->erase(cards->begin());
	return true;
}
