#include "Position.hpp"

Position::Position(): x(0), y(0), z(0) {
	std::cout << "Positon default constructor called" << std::endl;
}

Position::Position(int x, int y, int z): x(x), y(y), z(z) {
	std::cout << "Position constructor called with x: " << x;
	std::cout << ", y: " << y;
	std::cout << " ,z: " << z << std::endl;
}

Position::~Position() {
	std::cout << "Position destructor called" << std::endl;
}
