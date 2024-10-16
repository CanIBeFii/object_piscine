#pragma once

#include <iostream>
#include "Worker.hpp"

class Worker;

class Shovel {
	private:
		int numberOfUses;
		Worker* currentWorker;

	public:
		Shovel();
		Shovel(int uses);
		Shovel(const Shovel& copy);
		~Shovel();

		int getNumberOfUses();
		void use();

		void leaveWorker();
		void assignWorker(Worker* new_worker);
		friend class Worker;
};