#pragma once

#include <iostream>
#include "Tool.hpp"
#include "Worker.hpp"

class Worker;

class Shovel: public Tool {
	public:
		Shovel();
		Shovel(int uses);
		Shovel(const Shovel& copy);
		~Shovel();

		void use();
		friend class Worker;
};