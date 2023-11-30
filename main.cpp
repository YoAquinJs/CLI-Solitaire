#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <random>
#include <iomanip>

#include "classes/card.hpp"
#include "classes/cardPile.hpp"
#include "classes/column.hpp"
#include "magic_enum/magic_enum.hpp"

//Run
//g++ *.cpp classes/card.cpp -o main && ./main
int main(){
	std::cout << "--------------------------Solitarie--------------------------\n";
	std::cout << std::boolalpha;
	
	Card card2(CardSuit::CLUBS, CardRank::TWO);
	Card card3(CardSuit::DIAMONDS, CardRank::THREE);
	Card card4(CardSuit::CLUBS, CardRank::FOUR);

	CardColumn column1({&card2,&card3,&card4});
	CardColumn column2({&card4});

	return 0;
}