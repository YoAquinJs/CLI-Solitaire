#include <string>
#include <vector>

#include "gameLogic/gameLogic.hpp"
#include "classes/piles.hpp"
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
	Game game;

	//Sections
	game.drawSection.AddPile(new DrawPile(deck.GetRange(drawDeckSize)));
	game.drawSection.AddPile(new CardPile(new std::vector<Card*>()));

	for (int i = 0; i < suitSize; i++){
		game.foundationSection.AddPile(new Foundation());
	}

	for (int i = 1; i <= tableuColumns; i++){
		game.tableauSection.AddPile(new Column(deck.GetRange(i)));
	}

	game.InitializeCursors();

	//Card Pile links
	game.drawSection.GetAt(0)->LinkTo(game.drawSection.GetAt(1), Direction(1,0));
	game.drawSection.GetAt(0)->LinkTo(game.tableauSection.GetAt(0), Direction(0,-1));

	game.drawSection.GetAt(1)->LinkTo(game.foundationSection.GetAt(0), Direction(1,0));
	game.drawSection.GetAt(1)->LinkTo(game.tableauSection.GetAt(1), Direction(0,-1));

	game.foundationSection.GetAt(0)->LinkTo(game.foundationSection.GetAt(1), Direction(1,0));
	game.foundationSection.GetAt(0)->LinkTo(game.tableauSection.GetAt(3), Direction(0,-1));
	
	game.foundationSection.GetAt(1)->LinkTo(game.foundationSection.GetAt(2), Direction(1,0));
	game.foundationSection.GetAt(1)->LinkTo(game.tableauSection.GetAt(4), Direction(0,-1));

	game.foundationSection.GetAt(2)->LinkTo(game.foundationSection.GetAt(3), Direction(1,0));
	game.foundationSection.GetAt(2)->LinkTo(game.tableauSection.GetAt(5), Direction(0,-1));

	game.foundationSection.GetAt(3)->LinkTo(game.tableauSection.GetAt(6), Direction(0,-1));
	
	game.tableauSection.GetAt(0)->LinkTo(game.tableauSection.GetAt(1), Direction(1,0));
	game.tableauSection.GetAt(1)->LinkTo(game.tableauSection.GetAt(2), Direction(1,0));
	game.tableauSection.GetAt(2)->LinkTo(game.tableauSection.GetAt(3), Direction(1,0));
	game.tableauSection.GetAt(3)->LinkTo(game.tableauSection.GetAt(4), Direction(1,0));
	game.tableauSection.GetAt(4)->LinkTo(game.tableauSection.GetAt(5), Direction(1,0));
	game.tableauSection.GetAt(5)->LinkTo(game.tableauSection.GetAt(6), Direction(1,0));

	//Game Loop
	int moveCount = 0;
	bool inGame = true;
	while (inGame){
		Render(&game, moveCount);
		Update(&game, drawDeckSize, moveCount);
	}

	return 0;
}
