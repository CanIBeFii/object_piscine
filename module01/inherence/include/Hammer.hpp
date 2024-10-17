#pragma once

#include <iostream>
#include "Tool.hpp"
#include "Worker.hpp"

class Worker;

class Hammer: public Tool {
	public:
		Hammer();
		Hammer(int uses);
		Hammer(const Hammer& copy);
		~Hammer();

		void use();
		friend class Worker;
};