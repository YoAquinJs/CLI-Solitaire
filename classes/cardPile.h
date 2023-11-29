#include <vector>
#include "card.h"

class CardPile{
	protected:
		std::vector<Card*> cards;
		virtual void AddCard(Card* card){
			cards.push(card);
		}
		virtual bool CanAddCard(Card* card){
			return true;
		}

	public:
		CardPile(std::vector<Card*> cards) : cards(cards) {}

		bool TryAddCard(Card* card){
			if (!CanAddCard(card))
				return false;
			
			AddCard(card);
			return true;
		}
		void RemoveLast(){
			cards.pop();
		}
		Card* GetLast(){
			return cards.top();
		}
};