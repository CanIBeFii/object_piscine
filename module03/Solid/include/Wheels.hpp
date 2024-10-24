#pragma once

#include <iostream>

class Wheels {
	public:
		Wheels() {
			std::cout << "Constructor of Wheels called" << std::endl;
		}
		~Wheels() {
			std::cout << "Destructor of Wheels called" << std::endl;
		}
		void	turn_wheel(int angle) {
			std::cout << "The wheels are turning by " << angle << " degrees" << std::endl;
		}
		void	straighten_wheels() {
			std::cout << "The wheels have been straighten" << std::endl;
		}
};
