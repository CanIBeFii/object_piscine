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
	std::set<Tool*>::iterator iter = tools.find(tool);
	if (tool == NULL && *iter == NULL) {
		std::cout << "Couldn't remove tool" << std::endl;
		return;
	}
	tools.erase(iter);
	tool->assignWorker(NULL);
}

void Worker::useTool(Tool* tool) {
	std::cout << "Use Tool called" << std::endl;
	if (tool == NULL && tools.find(tool) == tools.end()) {
		std::cout << "Couldn't use tool because it's a skill issue" << std::endl;
		return ;
	}
	tool->use();
}

void Worker::joinWorkshop(Workshop* workshop) {
	std::set<Workshop*>::iterator iter = workshops.find(workshop);
	if (iter != workshops.end()) {
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
	std::set<Workshop*>::iterator iter = workshops.find(workshop);
	if (iter == workshops.end()) {
		std::cout << "Worker is not inside this workshop" << std::endl;
		return ;
	}
	workshops.erase(iter);
}

void Worker::work(Workshop* workshop) {
	if (workshops.find(workshop) == workshops.end()) {
		std::cout << "Worker is not in this workshop to work" << std::endl;
		return ;
	}
	std::cout << "Working working working" << std::endl;
}