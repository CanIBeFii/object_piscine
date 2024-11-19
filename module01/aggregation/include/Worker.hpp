#pragma once

#include "Position.hpp"
#include "Shovel.hpp"
#include "Statistic.hpp"
#include <map>

class Shovel;

class Worker {
private:
  Position coordonnee;
  Statistic stat;
  Shovel *shovel;
  static std::map<Worker *, Shovel *> who_has_shovel;

public:
  Worker();
  Worker(Position coord, Statistic statistic);
  ~Worker();

  Position &getCoordonnee();
  Statistic &getStat();

  void assignShovel(Shovel *new_shovel);
  void removeShovel();
  void useShovel();
};
