#include "cardPile.hpp"

class CardColumn : public CardPile {
	private:
		bool CanAddCard(Card* card) override;
	public:
		CardColumn DivideFrom(int index);
};