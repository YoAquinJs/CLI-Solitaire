#pragma once

#include "section.hpp"
#include "cursor.hpp"

enum class GameState { START, ONGAME, WON };

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
	Section* GetPileSection(CardPile* pile);
};
