#pragma once

#include <vector>
#include <map>
#include "cardPile.hpp"
#include "direction.hpp"

class Section{
	std::vector<CardPile*> piles;
	std::map<Direction, Section*> surroundingSections;

	public:
		Section();
		~Section();
		
		int Count();
		CardPile* GetAt(int index);
		Section* GetSurroundingSection(Direction direction);
		
		void AddPile(CardPile* pile);
		void LinkSurroundingSection(Direction direction, Section* section);
};
