#pragma once

#include <iostream>

class Transmission {
	public:
		Transmission() {
			std::cout << "Constructor of Transmission called" << std::endl;
		}

		~Transmission() {
			std::cout << "Destructor of Transmission called" << std::endl;
		}

		void	shift_gears_up(){
			std::cout << "Gears have been shifted up" << std::endl;
		}

		void	shift_gears_down() {
			std::cout << "Gears have been shifted down" << std::endl;
		}

		void	reverse() {
			std::cout << "Changes to reverse gear" << std::endl;
		}
};
