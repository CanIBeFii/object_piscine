#include <iostream>
#include "Position.hpp"
#include "Statistic.hpp"
#include "Worker.hpp"

int main() {
	{
		Worker worker(Position(1, 2, 3), Statistic(30, 55));
		Shovel shovel;
		std::cout << std::endl;

		worker.useShovel();
		worker.assignShovel(&shovel);
		worker.useShovel();

		std::cout << std::endl;
		Worker better_worker;
		better_worker.assignShovel(&shovel);
		better_worker.useShovel();
		worker.useShovel();
	}
    return 0;
}