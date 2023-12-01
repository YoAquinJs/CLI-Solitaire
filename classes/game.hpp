#pragma once

#include "section.hpp"

enum class GameState { START, ONGAME, WON, LOSS };

struct Game{
	Section drawSection;
	Section foundationSection;
	Section tableuSection;

	Game();
	
	private:
		GameState state;
};