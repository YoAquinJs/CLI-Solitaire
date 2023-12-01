#include <string>
#include <iostream>
#include <cstdlib>

#include "gameLogic.hpp"
#include "utils.hpp"

void Render(Game* game){
	#ifdef _WIN32 // For Windows systems
        system("cls");
    #else // For Unix-based systems
        system("clear");
    #endif

	ColorPrint("--------------------------Solitarie--------------------------", GREEN);
	if (game->state == GameState::START)
		return;

	PrintLine("");

	PrintLine("rendering....");

	PrintLine("");
}