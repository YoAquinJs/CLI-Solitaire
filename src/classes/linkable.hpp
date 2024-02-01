#pragma once

#include <map>

struct Direction{
	int x;
	int y;

	Direction(int x, int y);
};

bool operator<(const Direction& l, const Direction& r);

template<typename T>
class Linkable{
	std::map<Direction, T*> links;

	public:
		T* GetLinkAt(Direction direction){
			auto surrounding = links.find(direction);
			if (surrounding != links.end())
				return surrounding->second;

			return nullptr;
		}
		void LinkTo(T* linkable, Direction direction){
			if (links.find(direction) != links.end()){
				return;
			}

			links.insert({direction, linkable});
			linkable->LinkTo(static_cast<T*>(this), Direction(direction.x*-1,direction.y*-1));
		}
};
