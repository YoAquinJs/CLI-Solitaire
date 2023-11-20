#include "card.h"

class Deck{
	private:
		Card** cards;

	public:
		Deck() {
			int suitSize = static_cast<int>(CardSuit::CLUBS)+1;
			int rankSize = static_cast<int>(CardRank::KING)+1;
			cards = new Card*[suitSize*rankSize];

			for (int i = 0; i <= suitSize; ++i) {
    		    CardSuit suit = static_cast<CardSuit>(i);
				for (int j = 0; j <= rankSize; ++j) {
    		 	   	CardRank rank = static_cast<CardRank>(i);
					cards[(i*rankSize)+j] = new Card(suit, rank);
    			}
    		}
		}
		void Shuffle(){

		}
};