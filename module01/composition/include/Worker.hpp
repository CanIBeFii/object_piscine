#pragma once

#include "Position.hpp"
#include "Statistic.hpp"

class Worker {
	private:
		Position coordonnee;
		Statistic stat;
	public:
		Worker();
		Worker(Position coord, Statistic statistic);
		Worker(const Worker& copy);
		~Worker();

		Position& getCoordonnee();
		Statistic& getStat();
};