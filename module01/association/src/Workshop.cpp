#include "Workshop.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"

Workshop::Workshop(enum ToolType type): type_of_tool(type) {
	std::cout << "Worshop default constructor called" << std::endl;
}

Workshop::Workshop(const Workshop& copy):
	workers(copy.workers.begin(), copy.workers.end()),
	type_of_tool(copy.type_of_tool)
	{
		std::cout << "Worshop copy constructor called" << std::endl;
}

Workshop::~Workshop() {}

ToolType Workshop::getToolType() const {
	return type_of_tool;
}

bool Workshop::registerWorker(Worker* worker) {
	if (type_of_tool == SHOVEL) {
		Shovel* tool_pointer = worker->getTool<Shovel>();
		if (tool_pointer == NULL) {
			std::cout << "Worker cannot register to this workshop :[" << std::endl;
			return false;
		}
	} else {
		Hammer* tool_pointer = worker->getTool<Hammer>();
		if (tool_pointer == NULL) {
			std::cout << "Worker cannot register to this workshop :[" << std::endl;
			return false;
		}
	}
	workers.insert(worker);
	return true;
}

void	Workshop::removeWorker(Worker* worker) {
	worker->removeWorkshop(this);
	workers.erase(worker);
}

void	Workshop::executeWorkDay() {
	for (std::set<Worker*>::iterator iter = workers.begin();
		iter != workers.end();
		++iter)
		{
			(*iter)->work(this);
		}
}
