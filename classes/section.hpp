#pragma once

#include <vector>

#include "linkable.hpp"
#include "cardPile.hpp"

class Section{
	std::vector<CardPile*> piles;

	public:
		Section();
		~Section();
		
		int Count();
		int GetIndexOf(CardPile* pile);
		CardPile* GetAt(int index);
		
		void AddPile(CardPile* pile);
};
