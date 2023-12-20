#include "game.hpp"
#include "section.hpp"

Game::Game() : state(GameState::START), drawSection(Section()), foundationSection(Section()), tableuSection(Section()) {}

Game::~Game(){
	delete cursor1;
	delete cursor2;
}

void Game::SetCursors(){
	cursor1 = new Cursor(&drawSection, 0);
	cursor2 = new Cursor(&tableuSection, 0);
}

Section* Game::GetPileSection(CardPile* pile){
	if(tableuSection.GetIndexOf(pile) != -1)
		return &tableuSection;
	if(foundationSection.GetIndexOf(pile) != -1)
		return &foundationSection;
	if(drawSection.GetIndexOf(pile) != -1)
		return &drawSection;
	
	return nullptr;
}
