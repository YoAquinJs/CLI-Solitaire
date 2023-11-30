#include "cardPile.hpp"
#include "direction.hpp"
#include "section.hpp"

class Cursor{
	private:
		CardPile* pile;
		unsigned int index;
	
	public:
		bool locked;
		void Move(Direction direction, Section section);
		unsigned int GetIndex();
		CardPile* GetPile();
		Card* GetCard();
};