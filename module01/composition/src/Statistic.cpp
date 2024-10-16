#include "Statistic.hpp"

Statistic::Statistic(): level(0), exp(0) {
	std::cout << "Statistic default constructor called" << std::endl;
}

Statistic::Statistic(int init_level, int init_exp): level(init_level), exp(init_exp) {
	std::cout << "Statistic constructor called with level: " << level;
	std::cout << ", exp: " << exp << std::endl;
}

Statistic::~Statistic() {
	std::cout << "Statistic destructor called" << std::endl;
}