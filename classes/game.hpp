#pragma once

#include "section.hpp"

enum class GameState { START, ONGAME, WON };

struct Game{
	GameState state;
	
	Section drawSection;
	Section foundationSection;
	Section tableuSection;

	Game();
};