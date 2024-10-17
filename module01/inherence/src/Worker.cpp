#include "Worker.hpp"

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
		new_tool->current_worker = this;
	}
}

void Worker::removeTool(Tool *tool) {
	std::cout << "Remove shovel called" << std::endl;
	if (tool != NULL && tools.erase(tool) != 0) {
		tool->current_worker = NULL;
	}
}

void Worker::useTool(Tool* tool) {
	std::cout << "Use Tool called" << std::endl;
	if (tool != NULL && tools.find(tool) != tools.end()) {
		tool->use();
		return ;
	}
	std::cout << "Couldn't use tool because it's a skill issue" << std::endl;
}