#pragma once

#include <iostream>
#include <Worker.hpp>
#include <set>

class Worker;

template <typename T> 
class Workshop {
	private:
		std::set<Worker*> workers;
	public:
		Workshop() {
			std::cout << "Worshop default constructor called" << std::endl;
		}

		Workshop(const Workshop& copy): workers(copy.workers.begin(), copy.workers.end()) {
			std::cout << "Worshop copy constructor called" << std::endl;
		}

		void registerWorker(Worker* worker) {
			T* tool_pointer = worker->getTool<T>();
			if (tool_pointer == NULL) {
				std::cout << "Worker cannot register to this workshop :[" << std::endl;
			}
			workers.insert(worker);
		}

		void removeWorker(Worker* worker) {
			workers.erase(worker);
		}

		void executeWorkDay() {
			for (std::set<Worker*>::iterator iter = workers.begin();
				iter != workers.end();
				++iter)
				{
					*iter->work();
				}
		}
};