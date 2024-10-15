#include <iostream>
#include "Position.hpp"
#include "Statistic.hpp"
#include "Worker.hpp"

int main() {
	{
		Worker worker;
	}
	{
		Worker worker(Position(1, 2, 3), Statistic(30, 55));
	}
	{
		Worker worker(Position(1, 2, 3), Statistic(30, 55));
		Worker woke(worker);
	}
    return 0;
}