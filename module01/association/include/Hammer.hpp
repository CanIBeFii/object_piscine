#pragma once

#include <iostream>
#include "Tool.hpp"

class Hammer: public Tool {
	public:
		Hammer();
		Hammer(int uses);
		Hammer(const Hammer& copy);
		~Hammer();

		void use();
};