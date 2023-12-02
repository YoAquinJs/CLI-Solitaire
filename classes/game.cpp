#include "game.hpp"
#include "section.hpp"

Game::Game() : state(GameState::START), drawSection(Section()), foundationSection(Section()), tableuSection(Section()),
			   cursor1(new Cursor(&drawSection)), cursor2(new Cursor(&tableuSection)) {}

Game::~Game(){
	delete cursor1;
	delete cursor2;
}
