#include "game.hpp"
#include "section.hpp"

Game::Game() : state(GameState::START), drawSection(Section()), foundationSection(Section()), tableauSection(Section()),
				cursor1(nullptr), cursor2(nullptr), renderMatrix() {}

Game::~Game(){
	delete cursor1;
	delete cursor2;
}

void Game::InitializeCursors(){
	cursor1 = new Cursor(&drawSection, 0);
	cursor2 = new Cursor(&tableauSection, 0);
}

Section* Game::GetPileSection(CardPile* pile){
	if(tableauSection.GetIndexOf(pile) != -1)
		return &tableauSection;
	if(foundationSection.GetIndexOf(pile) != -1)
		return &foundationSection;
	if(drawSection.GetIndexOf(pile) != -1)
		return &drawSection;
	
	return nullptr;
}
