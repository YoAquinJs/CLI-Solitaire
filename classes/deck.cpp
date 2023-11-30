#include <time.h>

#include "deck.hpp"

void Deck::swap (Card *a, Card *b) { 
    Card temp = *a; 
    *a = *b; 
    *b = temp; 
} 

Deck::Deck() : fetchedCards(0) {
	int suitSize = static_cast<int>(CardSuit::CLUBS)+1;
	int rankSize = static_cast<int>(CardRank::KING)+1;
	deckSize = suitSize*rankSize;
	cards = new Card*[deckSize];

	for (int i = 0; i <= suitSize; ++i) {
	    CardSuit suit = static_cast<CardSuit>(i);
		for (int j = 0; j <= rankSize; ++j) {
	 	   	CardRank rank = static_cast<CardRank>(i);
			cards[(i*rankSize)+j] = new Card(suit, rank);
		}
	}
}

// Using Fisher–Yates algorithm
void Deck::Shuffle(){
	srand (time(NULL));
	for (int i = deckSize - 1; i > 0; i--) { 
	    int j = rand() % (i + 1); 
	    swap(cards[i], cards[j]); 
	} 
}

std::vector<Card*> Deck::GetRange(int count){
	std::vector<Card*> pileStack;

	for (int i = fetchedCards; i < fetchedCards+count; i++) {
		pileStack.push_back(cards[i]);
	}

	fetchedCards += count;
	return pileStack;
}

Deck::~Deck(){
	// Free allocated memory
	for (int i = 0; i < deckSize; ++i) {
		delete[] cards[i];
	}
	delete[] cards;
}