#include "direction.hpp"

Direction::Direction(int x, int y) : x(x), y(y) {}

bool Direction::operator<(const Direction& other) const {
    return x == other.x && y == other.y;
}