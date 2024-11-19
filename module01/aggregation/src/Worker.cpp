#include "Worker.hpp"

std::map<Worker *, Shovel *> Worker::who_has_shovel;

Worker::Worker() : coordonnee(Position()), stat(Statistic()) {
  std::cout << "Worker default constructor called" << std::endl;
}

Worker::Worker(Position coord, Statistic statistic)
    : coordonnee(coord), stat(statistic) {
  std::cout << "Worker constructor called" << std::endl;
}

Worker::~Worker() {
  std::cout << "Worker destructor called" << std::endl;
  who_has_shovel.erase(this);
}

Position &Worker::getCoordonnee() {
  std::cout << "Worker getCoordonnee called" << std::endl;
  return coordonnee;
}

Statistic &Worker::getStat() {
  std::cout << "Worker getStat called" << std::endl;
  return stat;
}

void Worker::assignShovel(Shovel *new_shovel) {
  std::cout << "Assign shovel called" << std::endl;
  if (new_shovel == NULL) {
    return;
  }
  for (std::map<Worker *, Shovel *>::iterator iter = who_has_shovel.begin();
       iter != who_has_shovel.end(); ++iter) {
    if (iter->second == new_shovel) {
      iter->second = NULL;
      iter->first->shovel = NULL;
    }
  }
  who_has_shovel.find(this)->second = new_shovel;
  shovel = new_shovel;
}

void Worker::removeShovel() {
  std::cout << "Remove shovel called" << std::endl;
  if (shovel != NULL) {
    who_has_shovel.find(this)->second = NULL;
    shovel = NULL;
  }
}

void Worker::useShovel() {
  std::cout << "Use shovel called" << std::endl;
  if (shovel) {
    shovel->use();
    return;
  }
  std::cout << "Couldn't use shovel because i don't have any" << std::endl;
}
