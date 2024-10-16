#include "Shovel.hpp"

Shovel::Shovel(): numberOfUses(0) {
	std::cout << "Shovel default constructor called" << std::endl;
}

Shovel::Shovel(int uses): numberOfUses(uses) {
	std::cout << "Shovel constructor called with uses: " << uses << std::endl;
}

Shovel::Shovel(const Shovel& copy): numberOfUses(copy.numberOfUses) {
	std::cout << "Shovel copy constructor called" << std::endl;
}

Shovel::~Shovel() {
	std::cout << "Shovel destructor called" << std::endl;
}

int Shovel::getNumberOfUses() {
	return numberOfUses;
}

void Shovel::use(){
	std::cout << "Shovel is being used" << std::endl;
	numberOfUses++;
}

void Shovel::leaveWorker() {
	std::cout << "Leave worker called" << std::endl;
	if (currentWorker) {
		currentWorker->removeShovel();
	}
	currentWorker = NULL;
}
