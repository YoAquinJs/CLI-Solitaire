#include "cardPile.h"

class CardColumn : public CardPile {
	private:
		bool CanAddCard(Card* card) override {
			Card* topStackCard = this->cards.top();
			return card->IsLesserRank(topStackCard) && card->IsDiffColor(topStackCard);
		}
	public:
		CardColumn DivideFrom(int index){
			CardColumn newColumn;

		}
};