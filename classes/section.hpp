#pragma once

#include <vector>
#include <map>
#include "cardPile.hpp"
#include "direction.hpp"

class Section{
	private:
		std::vector<CardPile*> piles;
		std::map<Direction, Section*> surroundingSections;

	public:
		Section();
		~Section();
		
		int Count();
		void LinkSurroundingSection(Direction direction, Section* section);
		Section* GetSurroundingSection(Direction direction);
		CardPile* GetAt(int index);
		void AddPile(CardPile* pile);
};