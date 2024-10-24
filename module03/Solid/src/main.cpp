#include <iostream>
#include "Car.hpp"

int main() {
	Car car;

	std::cout << std::endl;
	car.engine.start();
	car.engine.accelerate(100);
	car.transmission.shift_gears_up();
	car.transmission.shift_gears_down();
	car.wheels.turn_wheel(45);
	car.transmission.shift_gears_down();
	car.wheels.straighten_wheels();
	car.brakes.apply_force_on_brakes(10);
	car.brakes.apply_emergency_brakes();
	car.transmission.reverse();
	car.engine.stop();
	std::cout << std::endl;

    return 0;
}
