#pragma once

#include "Position.hpp"
#include "Statistic.hpp"
#include "Shovel.hpp"

class Shovel;

class Worker {
	private:
		Position coordonnee;
		Statistic stat;
		Shovel* shovel;
	public:
		Worker();
		Worker(Position coord, Statistic statistic);
		Worker(const Worker& copy);
		~Worker();

		Position& getCoordonnee();
		Statistic& getStat();

		void assignShovel(Shovel* new_shovel);
		void removeShovel();
		void useShovel();

		friend class Shovel;
};