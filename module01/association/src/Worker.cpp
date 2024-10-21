#include "Worker.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"

Worker::Worker(): coordonnee(Position()), stat(Statistic()) {
	std::cout << "Worker default constructor called" << std::endl;
}

Worker::Worker(Position coord, Statistic statistic): coordonnee(coord), stat(statistic) {
	std::cout << "Worker constructor called" << std::endl;
}

Worker::Worker(const Worker& copy): coordonnee(copy.coordonnee), stat(copy.stat) {
	std::cout << "Worker copy constructor called" << std::endl;
}

Worker::~Worker() {
	std::cout << "Worker destructor called" << std::endl;
}

Position& Worker::getCoordonnee() {
	std::cout << "Worker getCoordonnee called" << std::endl;
	return coordonnee;
}

Statistic& Worker::getStat() {
	std::cout << "Worker getStat called" << std::endl;
	return stat;
}

void Worker::assignTool(Tool* new_tool) {
	std::cout << "Assign tool called" << std::endl;
	if (new_tool) {
		new_tool->leaveWorker();
		tools.insert(new_tool);
		new_tool->assignWorker(this);
	}
}

void Worker::removeTool(Tool *tool) {
	std::cout << "Remove shovel called" << std::endl;
	if (tool == NULL && tools.erase(tool) == 0) {
		return;
	}
	tool->assignWorker(NULL);
}

void Worker::useTool(Tool* tool) {
	std::cout << "Use Tool called" << std::endl;
	if (tool != NULL && tools.find(tool) != tools.end()) {
		tool->use();
		return ;
	}
	std::cout << "Couldn't use tool because it's a skill issue" << std::endl;
}

void Worker::joinWorkshop(Workshop* workshop) {
	if (workshops.find(workshop) != workshops.end()) {
		std::cout << "Already in this workshop" << std::endl;
		return ;
	}
	if (workshop->registerWorker(this)) {
		workshops.insert(workshop);
	}
}

void	Worker::leaveWorkshop(Workshop* workshop) {
	workshop->removeWorker(this);
}

void Worker::removeWorkshop(Workshop* workshop) {
	if (workshops.find(workshop) == workshops.end()) {
		std::cout << "Worker is not inside this workshop" << std::endl;
		return ;
	}
	workshops.erase(workshop);
}

void Worker::work(Workshop* workshop) {
	if (workshops.find(workshop) == workshops.end()) {
		std::cout << "Worker is not in this workshop to work" << std::endl;
		return ;
	}
	std::cout << "Working working working" << std::endl;
}