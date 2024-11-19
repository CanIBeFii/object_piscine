#include "Shovel.hpp"

Shovel::Shovel() : numberOfUses(0) {
  std::cout << "Shovel default constructor called" << std::endl;
}

Shovel::Shovel(int uses) : numberOfUses(uses) {
  std::cout << "Shovel constructor called with uses: " << uses << std::endl;
}

Shovel::~Shovel() { std::cout << "Shovel destructor called" << std::endl; }

void Shovel::use() {
  std::cout << "Shovel is being used" << std::endl;
  numberOfUses++;
}
