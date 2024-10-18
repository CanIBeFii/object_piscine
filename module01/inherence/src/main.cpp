#include <iostream>
#include "Position.hpp"
#include "Statistic.hpp"
#include "Worker.hpp"
#include "Hammer.hpp"

int main() {
	{
		Worker worker(Position(1, 2, 3), Statistic(30, 55));
		Worker woke;
		Shovel shovel;
		Shovel shovel2;
		Hammer hammer;

		std::cout << std::endl;

		worker.assignTool(&shovel);
		worker.assignTool(&shovel2);
		worker.assignTool(&hammer);

		Hammer* hammer_pointer = worker.getTool<Hammer>();
		if (hammer_pointer != &hammer) {
			std::cout << "Something went wrong" << std::endl;
		}
	}
    return 0;
}