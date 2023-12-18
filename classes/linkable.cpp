#include "linkable.hpp"

template<typename T>
T* Linkable<T>::GetLinkAt(Direction direction){
	auto surrounding = links.find(direction);
	if (surrounding != links.end())
		return surrounding->second;
		
	return nullptr;
}

template <typename T>
void Linkable<T>::LinkTo(T* linkable, Direction direction){
	if (links.find(direction) != links.end()){
		return;
	}

	links.insert({direction, linkable});
	linkable->LinkSurroundingPile(Direction(direction.x*-1,direction.y*-1), this);
}
