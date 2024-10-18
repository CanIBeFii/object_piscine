#include "Shovel.hpp"

Shovel::Shovel(): Tool() {
	std::cout << "Shovel default constructor called" << std::endl;
}

Shovel::Shovel(int uses): Tool(uses) {
	std::cout << "Shovel constructor called with uses: " << uses << std::endl;
}

Shovel::Shovel(const Shovel& copy): Tool(copy) {
	std::cout << "Shovel copy constructor called" << std::endl;
}

Shovel::~Shovel() {
	std::cout << "Shovel destructor called" << std::endl;
}

void Shovel::use(){
	std::cout << "Dig Dig Dig" << std::endl;
	number_of_uses++;
}