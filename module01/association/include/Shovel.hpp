#pragma once

#include <iostream>
#include "Tool.hpp"

class Shovel: public Tool {
	public:
		Shovel();
		Shovel(int uses);
		Shovel(const Shovel& copy);
		~Shovel();

		void use();
};