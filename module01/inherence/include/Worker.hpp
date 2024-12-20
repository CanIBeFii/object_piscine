#pragma once

#include "Position.hpp"
#include "Statistic.hpp"
#include "Tool.hpp"
#include <map>
#include <set>
#include <utility>

class Tool;
class Worker {
private:
  Position coordonnee;
  Statistic stat;
  std::set<Tool *> tools;
  static std::map<Tool *, Worker *> who_has_tool;

public:
  Worker();
  Worker(Position coord, Statistic statistic);
  Worker(const Worker &copy);
  ~Worker();

  Position &getCoordonnee();
  Statistic &getStat();

  void assignTool(Tool *new_tool);
  void removeTool(Tool *tool);
  void useTool(Tool *tool);

  template <typename T> T *getTool() {
    for (std::set<Tool *>::iterator iter = tools.begin(); iter != tools.end();
         ++iter) {
      T *tool = dynamic_cast<T *>(*iter);
      if (tool != NULL) {
        return tool;
      }
    }
    return NULL;
  };
};
