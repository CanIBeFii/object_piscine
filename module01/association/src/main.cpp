#include <iostream>
#include "Position.hpp"
#include "Statistic.hpp"
#include "Worker.hpp"
#include "Hammer.hpp"
#include "Shovel.hpp"

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
		Shovel* shovel_pointer = worker.getTool<Shovel>();
		if (shovel_pointer != &shovel) {
			std::cout << "Something went wrong oh noo :(" << std::endl;
		}
		woke.assignTool(&shovel);
		worker.useTool(&shovel);
		worker.useTool(&shovel2);
		worker.useTool(&hammer);
		Hammer* hammer_null_pointer = woke.getTool<Hammer>();
		if (hammer_null_pointer != NULL) {
			std::cout << "Somehow found one hammer, wtff" << std::endl;
		}
	}
    return 0;
}