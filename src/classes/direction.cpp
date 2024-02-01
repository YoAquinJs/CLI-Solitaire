#include "linkable.hpp"

Direction::Direction(int x, int y) : x(x), y(y) {}

bool operator<(const Direction& l, const Direction& r) {
     return (l.x<r.x || (l.x==r.x && l.y<r.y));
}
