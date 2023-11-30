#pragma once

#include <vector>
#include <map>
#include "cardPile.hpp"
#include "direction.hpp"

class Section{
	private:
		const int count;
		std::vector<CardPile*> piles;
		std::map<Direction, Section*> surroundingSections;

	public:
		Section(int count);
		~Section();
		
		int Count();
		void LinkSurroundingSection(Direction direction, Section* section);
		Section* GetSurroundingSection(Direction direction);
		CardPile* GetAt(int index);
};