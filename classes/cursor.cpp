#include "cursor.hpp"

void Cursor::Move(Direction direction, Section section){
	
}

unsigned int Cursor::GetIndex(){
	return index;
}

CardPile* Cursor::GetPile(){
	return pile;
}

Card* Cursor::GetCard(){
	return pile->GetIndex(index);
}