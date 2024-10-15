#pragma once

#include <iostream>

struct Position {
	int x;
	int y;
	int z;

	Position();
	Position(int x, int y, int z);
	~Position();
};