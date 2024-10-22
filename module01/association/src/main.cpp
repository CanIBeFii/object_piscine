#include <iostream>
#include "Position.hpp"
#include "Statistic.hpp"
#include "Worker.hpp"
#include "Hammer.hpp"
#include "Shovel.hpp"
#include "Workshop.hpp"

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
		woke.assignTool(&hammer);
		Hammer* hammer_null_pointer = worker.getTool<Hammer>();
		if (hammer_null_pointer != NULL) {
			std::cout << "Somehow found one hammer, wtff" << std::endl;
		}
		std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;
	}
	{
		std::cout << std::endl;std::cout << std::endl;
		Worker worker(Position(1, 2, 3), Statistic(30, 55));
		Worker woke;
		Shovel shovel;
		Shovel shovel2;
		Hammer hammer;
		Workshop workshop_hammer(HAMMER);
		Workshop workshop_shovel(SHOVEL);

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
		woke.joinWorkshop(&workshop_hammer);
		woke.joinWorkshop(&workshop_shovel);
		worker.joinWorkshop(&workshop_shovel);
		std::cout << std::endl;
		std::cout << std::endl;

		woke.assignTool(&shovel);
		woke.joinWorkshop(&workshop_shovel);
		worker.removeTool(&hammer);
		woke.assignTool(&hammer);

		Hammer* hammer_null_pointer = worker.getTool<Hammer>();
		if (hammer_null_pointer != NULL) {
			std::cout << hammer_null_pointer << std::endl;
			std::cout << "Somehow found one hammer, wtff" << std::endl;
		}
		worker.joinWorkshop(&workshop_hammer);
		std::cout << std::endl;
	}
    return 0;
}