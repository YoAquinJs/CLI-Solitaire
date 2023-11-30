#include <vector>
#include <map>

#include "deck.h"
#include "foundation.h"

class FundationSection {
	public:
		std::map<CardSuit, std::vector<Foundation>> foundations;
		FundationSection() {
			int suitSize = static_cast<int>(CardSuit::CLUBS)+1;
			for (int i = 0; i <= suitSize; ++i) {
    		    CardSuit suit = static_cast<CardSuit>(i);

				foundations[suit] = std::vector<Foundation>();
    		}
		}
};