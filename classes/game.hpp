#pragma once

#include "section.hpp"
#include "cursor.hpp"

enum class GameState { START, ONGAME, WON };

struct Game{
	Card* renderMatrix[7][14];
	GameState state;		
	Cursor* cursor1;
	Cursor* cursor2;
	
	Section drawSection;
	Section foundationSection;
	Section tableuSection;

	Game();
	~Game();
};