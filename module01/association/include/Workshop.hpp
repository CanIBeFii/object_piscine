#pragma once

#include <Worker.hpp>
#include <iostream>
#include <set>

enum ToolType {
  SHOVEL,
  HAMMER,
};

class Worker;
class Workshop {
private:
  std::set<Worker *> workers;
  enum ToolType type_of_tool;

public:
  Workshop(enum ToolType type);
  Workshop(const Workshop &copy);
  ~Workshop();

  ToolType getToolType() const;

  void removeWorker(Worker *worker);
  bool registerWorker(Worker *worker);
  void executeWorkDay();
};
