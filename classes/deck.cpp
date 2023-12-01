#include <time.h>
#include <random>
#include <iostream>
#include "../magic_enum/magic_enum.hpp"
#include "../magic_enum/magic_enum_utility.hpp"
#include "deck.hpp"

void Deck::swap (Card *a, Card *b) {
    Card temp = *a;
    *a = *b;
    *b = temp;
}

Deck::Deck() : fetchedCards(0) {
	int suitSize = magic_enum::enum_count<CardSuit>();
	int rankSize = magic_enum::enum_count<CardRank>();
	deckSize = suitSize*rankSize;
	cards = new Card*[deckSize];
	
	int i = 0;
	magic_enum::enum_for_each<CardSuit>([&i, this] (auto val) mutable {
  		constexpr CardSuit suit = val;

		magic_enum::enum_for_each<CardRank>([&i, this] (auto val) mutable {
  			constexpr CardRank rank = val;

			cards[i] = new Card(suit, rank);
			i++;
		});
	});
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