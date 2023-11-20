#include <stack>
#include "card.h"

using namespace std;

class CardPile{
	private:
		stack<Card*> cards;
		virtual void AddCard(Card* card){
			cards.push(card);
		}
		virtual bool CanAddCard(Card* card){
			return true;
		}
	
	public:
		virtual bool TryAddCard(Card* card){
			if (!CanAddCard(card))
				return false;
			
			AddCard(card);
			return true;
		}
		void RemoveLast(Card* card){
			cards.pop();
		}
		Card* GetLast(){
			return cards.top();
		}
};