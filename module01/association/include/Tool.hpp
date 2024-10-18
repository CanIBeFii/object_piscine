#pragma once

#include <iostream>
#include "Worker.hpp"

class Worker;
class Tool {
	protected:
		int number_of_uses;
		Worker* current_worker;

	public:
		Tool();
		Tool(int uses);
		Tool(const Tool& copy);
		virtual ~Tool() = 0;

		int getNumberOsUses();
		virtual void use() = 0;

		void leaveWorker();
		void assignWorker(Worker* new_worker);
};