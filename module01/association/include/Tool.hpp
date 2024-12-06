#pragma once

#include <iostream>

class Worker;
class Tool {
protected:
  int number_of_uses;

public:
  Tool();
  Tool(int uses);
  Tool(const Tool &copy);
  virtual ~Tool();

  int getNumberOsUses();
  virtual void use() = 0;
};
