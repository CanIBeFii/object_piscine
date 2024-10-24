#pragma once

#include <iostream>

class Engine {
	public:
		Engine() {
			std::cout << "Constructor of Engine called" << std::endl;
		}
		~Engine() {
			std::cout << "Destructor of Engine called" << std::endl;
		}

		void	start() {
			std::cout << "The engine has started *vrrooom vrrommm*" << std::endl;
		}

		void	stop() {
			std::cout << "The engine has stoped :((" << std::endl;
		}

		void	accelerate(int speed) {
			std::cout << "Acelarate with a speed of " << speed << std::endl;
		}
};
