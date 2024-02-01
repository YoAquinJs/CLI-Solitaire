#pragma once

#include <functional>

#include "card.hpp"
#include "linkable.hpp"

enum class GameState { START, ONGAME, WON };

class Section{
	std::vector<CardPile*> piles;

	public:
		Section();
		~Section();
		
		int Count();
		int GetIndexOf(const CardPile* pile);
		CardPile* GetAt(int index);
		
		void AddPile(CardPile* pile);
};

class Cursor{
	CardPile* pile;
	Section* section;
	unsigned int cardIndex;

	public:
		bool locked;

		Cursor(Section* section , int pileIndex);
		
		int GetIndex();
		Card* GetCard();
		CardPile* GetPile();
		Section* GetSection();
		
		void SetIndexToZero();
		void Move(Direction direction, std::function<Section* (CardPile*)> getSection);
};

struct Game{
	GameState state;
	Card* renderMatrix[7][14];
	
	Cursor* cursor1;
	Cursor* cursor2;
	
	Section drawSection;
	Section foundationSection;
	Section tableauSection;

	Game();
	~Game();

	void InitializeCursors();
	Section* GetPileSection(const CardPile* pile);
};
