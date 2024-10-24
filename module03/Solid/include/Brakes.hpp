#pragma once

#include <iostream>

class Brakes {
	public:
		Brakes() {
			std::cout << "Constructor of Brakes called" << std::endl;
		}

		~Brakes() {
			std::cout << "Destructor of Brakes called" << std::endl;
		}

		void	apply_force_on_brakes(int force) {
			std::cout << "A force of: " << force << " was applied on the brakes." << std::endl;
		}

		void	apply_emergency_brakes(){
			std::cout << "Emergency stop initiated *screeechhhhhh* damn" << std::endl;
		}
};
