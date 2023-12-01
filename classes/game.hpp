#include "section.hpp"

enum class GameState { START, ONGAME, WON, LOSS };

struct Game{
	Section* drawSection;
	Section* foundationSection;
	Section* tableuSection;

	Game() : state(GameState::START), drawSection(), foundationSection(), tableuSection() {}
	
	private:
		GameState state;
};