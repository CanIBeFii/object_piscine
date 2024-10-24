#pragma once

#include <iostream>
#include "Brakes.hpp"
#include "Engine.hpp"
#include "Transmission.hpp"
#include "Wheels.hpp"

class Car {
	public:
		Brakes	brakes;
		Engine	engine;
		Transmission	transmission;
		Wheels	wheels;

		Car() {
			std::cout << "Constructor of Car called" << std::endl;
		}

		~Car() {
			std::cout << "Destructor of Car called" << std::endl;
		}
};
