#include <string>
#include <vector>
#include <iostream>

#include "gameLogic/gameLogic.hpp"
#include "classes/foundation.hpp"
#include "classes/drawPile.hpp"
#include "classes/column.hpp"
#include "classes/deck.hpp"
#include "classes/game.hpp"

/*Run Commands
valgrind --leak-check=full ./main
g++ gameLogic/*.cpp classes/*.cpp -o main main.cpp && ./main
g++-13 gameLogic/*.cpp classes/*.cpp -o main main.cpp && ./main
*/
int main(){
	std::cout << std::boolalpha;
	const int tableuColumns = 7;
	const int drawDeck = 52-(tableuColumns*(tableuColumns+1)/2);

	//Deck
	Deck deck;
	deck.Shuffle();

	//Game Object
	Game* game = new Game();

	//Sections
	game->drawSection.AddPile(new DrawPile(deck.GetRange(drawDeck)));
	game->drawSection.AddPile(new CardPile(new std::vector<Card*>()));

	for (int i = 0; i < suitSize; i++){
		game->foundationSection.AddPile(new Foundation());
	}

	for (int i = 1; i <= tableuColumns; i++){
		game->tableuSection.AddPile(new Column(deck.GetRange(i)));
	}

	//Section links
	game->drawSection.LinkSurroundingSection(Direction(1,0), &game->foundationSection);
	game->foundationSection.LinkSurroundingSection(Direction(-1,0), &game->drawSection);

	game->tableuSection.LinkSurroundingSection(Direction(0,1), &game->drawSection);
	game->foundationSection.LinkSurroundingSection(Direction(0,-1), &game->tableuSection);
	game->drawSection.LinkSurroundingSection(Direction(0,-1), &game->tableuSection);

	//Game Loop
	bool inGame = true;
	while (inGame){
		Render(game);
		Update(game, drawDeck);
	}

	return 0;
}
