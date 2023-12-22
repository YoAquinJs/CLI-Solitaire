#include <time.h>
#include <random>

#include "deck.hpp"

void Deck::swap (Card* a, Card* b) {
    Card temp = *a;
    *a = *b;
    *b = temp;
}

Deck::Deck() : fetchedCards(0) {
	deckSize = suitSize*rankSize;
	cards = new Card*[deckSize];
	
	for (int i = 0; i < suitSize; i++){
		CardSuit suit = static_cast<CardSuit>(i);
		for (int j = 0; j < rankSize; j++){
			CardRank rank = static_cast<CardRank>(j+1);
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

int Deck::GetSize(){
	return deckSize;
}


std::vector<Card*>* Deck::GetRange(int count){
	std::vector<Card*>* pileStack = new std::vector<Card*>();

	for (int i = fetchedCards; i < fetchedCards+count; i++) {
		pileStack->push_back(cards[i]);
	}

	fetchedCards += count;
	return pileStack;
}

Deck::~Deck(){
	for (int i = 0; i < deckSize; ++i) {
		delete cards[i];
	}
	delete[] cards;
}
