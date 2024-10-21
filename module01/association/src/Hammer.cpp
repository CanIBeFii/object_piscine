#include "Hammer.hpp"

Hammer::Hammer(): Tool() {
	std::cout << "Hammer default constructor called" << std::endl;
}

Hammer::Hammer(int uses): Tool(uses) {
	std::cout << "Hammer constructor called with uses: " << uses << std::endl;
}

Hammer::Hammer(const Hammer& copy): Tool(copy) {
	std::cout << "Hammer copy constructor called" << std::endl;
}

Hammer::~Hammer() {
	std::cout << "Hammer destructor called" << std::endl;
}

void	Hammer::use(){
	std::cout << "Hammer downnn!!!(live with honor, die with glory)" << std::endl;
	number_of_uses++;
}