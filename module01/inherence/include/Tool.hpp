#pragma once

#include <iostream>

class Tool {
protected:
  int number_of_uses;

public:
  Tool();
  Tool(int uses);
  virtual ~Tool() = 0;

  int getNumberOsUses();
  virtual void use() = 0;
};
