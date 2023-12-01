#include "game.hpp"
#include "section.hpp"

Game::Game() : state(GameState::START), drawSection(Section()), foundationSection(Section()), tableuSection(Section()),
			   cursor1(new Cursor(&tableuSection,1)), cursor2(new Cursor(&drawSection,2)) {}

Game::~Game(){
	delete cursor1;
	delete cursor2;
}
