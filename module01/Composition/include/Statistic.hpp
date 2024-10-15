#pragma once

#include <iostream>

struct Statistic {
	int level;
	int exp;

	Statistic();
	Statistic(int init_level, int init_exp);
	~Statistic();
};