#include "Worker.hpp"

Worker::Worker(): coordonnee(Position()), stat(Statistic()) {
	std::cout << "Worker default constructor called" << std::endl;
}

Worker::Worker(Position coord, Statistic stat): coordonnee(coord), stat(stat) {
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