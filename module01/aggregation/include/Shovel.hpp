#pragma once

#include <iostream>

struct Shovel {
  int numberOfUses;

  Shovel();
  Shovel(int uses);
  ~Shovel();

  void use();
};
