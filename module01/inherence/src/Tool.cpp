#include "Tool.hpp"

Tool::Tool() : number_of_uses(0) {
  std::cout << "Tool default constructor called" << std::endl;
}

Tool::Tool(int uses) : number_of_uses(uses) {
  std::cout << "Tool constructor called with uses: " << uses << std::endl;
}

Tool::~Tool() { std::cout << "Tool destructor called" << std::endl; }

int Tool::getNumberOsUses() { return number_of_uses; }
