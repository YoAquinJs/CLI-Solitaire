#include <string>
#include <vector>
#include <iostream>

#include "gameLogic/utils.hpp"
#include "gameLogic/gameLogic.hpp"
#include "classes/foundation.hpp"
#include "classes/drawPile.hpp"
#include "classes/column.hpp"
#include "classes/deck.hpp"
#include "classes/game.hpp"

/*Run Commands
- Windows
g++ gameLogic/*.cpp classes/*.cpp -o main main.cpp && ./main
- Linux
g++-13 gameLogic/*.cpp classes/*.cpp -o main main.cpp && ./main
g++-13 gameLogic/*.cpp classes/*.cpp -o main main.cpp && sudo valgrind --leak-check=full ./main
*/
int main(){
	//Deck
	Deck deck;
	deck.Shuffle();

	const int tableuColumns = 7;
	const int drawDeckSize = deck.GetSize()-(tableuColumns*(tableuColumns+1)/2);

	//Game Object
	Game* game = new Game();

	//Sections
	game->drawSection.AddPile(new DrawPile(deck.GetRange(drawDeckSize)));
	game->drawSection.AddPile(new CardPile(new std::vector<Card*>()));

	for (int i = 0; i < suitSize; i++){
		game->foundationSection.AddPile(new Foundation());
	}

	for (int i = 1; i <= tableuColumns; i++){
		game->tableuSection.AddPile(new Column(deck.GetRange(i)));
	}

	game->SetCursors();

	//Card Pile links
	game->drawSection.GetAt(0)->LinkTo(game->drawSection.GetAt(1), Direction(1,0));
	game->drawSection.GetAt(0)->LinkTo(game->tableuSection.GetAt(0), Direction(0,-1));

	game->drawSection.GetAt(1)->LinkTo(game->foundationSection.GetAt(0), Direction(1,0));
	game->drawSection.GetAt(1)->LinkTo(game->tableuSection.GetAt(1), Direction(0,-1));

	game->foundationSection.GetAt(0)->LinkTo(game->foundationSection.GetAt(1), Direction(1,0));
	game->foundationSection.GetAt(0)->LinkTo(game->tableuSection.GetAt(3), Direction(0,-1));
	
	game->foundationSection.GetAt(1)->LinkTo(game->foundationSection.GetAt(2), Direction(1,0));
	game->foundationSection.GetAt(1)->LinkTo(game->tableuSection.GetAt(4), Direction(0,-1));

	game->foundationSection.GetAt(2)->LinkTo(game->foundationSection.GetAt(3), Direction(1,0));
	game->foundationSection.GetAt(2)->LinkTo(game->tableuSection.GetAt(5), Direction(0,-1));

	game->foundationSection.GetAt(3)->LinkTo(game->tableuSection.GetAt(6), Direction(0,-1));
	
	game->tableuSection.GetAt(0)->LinkTo(game->tableuSection.GetAt(1), Direction(1,0));
	game->tableuSection.GetAt(1)->LinkTo(game->tableuSection.GetAt(2), Direction(1,0));
	game->tableuSection.GetAt(2)->LinkTo(game->tableuSection.GetAt(3), Direction(1,0));
	game->tableuSection.GetAt(3)->LinkTo(game->tableuSection.GetAt(4), Direction(1,0));
	game->tableuSection.GetAt(4)->LinkTo(game->tableuSection.GetAt(5), Direction(1,0));
	game->tableuSection.GetAt(5)->LinkTo(game->tableuSection.GetAt(6), Direction(1,0));

	//Game Loop
	bool inGame = true;
	while (inGame){
		Render(game);
		Update(game, drawDeckSize);
	}

	return 0;
}
