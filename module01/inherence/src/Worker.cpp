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

void Worker::assignShovel(Shovel* new_shovel) {
	std::cout << "Assign shovel called" << std::endl;
	if (new_shovel) {
		new_shovel->leaveWorker();
		shovel = new_shovel;
	}
}

void Worker::removeShovel() {
	std::cout << "Remove shovel called" << std::endl;
	if (shovel) {
		shovel->leaveWorker();
		shovel = NULL;
	}
}

void Worker::useShovel() {
	std::cout << "Use shovel called" << std::endl;
	if (shovel) {
		shovel->use();
		return ;
	}
	std::cout << "Couldn't use shovel because i don't have any" << std::endl;
}