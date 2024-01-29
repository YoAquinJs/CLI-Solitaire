#pragma once

struct Direction{
	int x;
	int y;

	Direction(int x, int y);
};

bool operator<(const Direction& l, const Direction& r);
