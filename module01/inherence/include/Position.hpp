#pragma once

#include <iostream>

struct Position {
	int x;
	int y;
	int z;

	Position();
	Position(int init_x, int init_y, int init_z);
	~Position();
};