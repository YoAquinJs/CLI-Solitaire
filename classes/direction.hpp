#pragma once

struct Direction{
	public:
		int x;
		int y;

		Direction(int x, int y);
		bool operator<(const Direction& other) const;
};