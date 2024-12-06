#include "Worker.hpp"
#include "Hammer.hpp"
#include "Shovel.hpp"
#include "Workshop.hpp"

std::map<Tool *, Worker *> Worker::who_has_tool;

Worker::Worker() : coordonnee(Position()), stat(Statistic()) {
  std::cout << "Worker default constructor called" << std::endl;
}

Worker::Worker(Position coord, Statistic statistic)
    : coordonnee(coord), stat(statistic) {
  std::cout << "Worker constructor called" << std::endl;
}

Worker::Worker(const Worker &copy)
    : coordonnee(copy.coordonnee), stat(copy.stat) {
  std::cout << "Worker copy constructor called" << std::endl;
}

Worker::~Worker() {
  std::cout << "Worker destructor called" << std::endl;
  for (std::map<Tool *, Worker *>::iterator iter = who_has_tool.begin();
       iter != who_has_tool.end(); ++iter) {
    if (iter->second == this) {
      iter->second = NULL;
    }
  }
  for (std::set<Workshop *>::iterator iter = workshops.begin();
       iter != workshops.end(); ++iter) {
    (*iter)->removeWorker(this);
  }
}

Position &Worker::getCoordonnee() {
  std::cout << "Worker getCoordonnee called" << std::endl;
  return coordonnee;
}

Statistic &Worker::getStat() {
  std::cout << "Worker getStat called" << std::endl;
  return stat;
}

void Worker::assignTool(Tool *new_tool) {
  std::cout << "Assign tool called" << std::endl;
  if (new_tool == NULL) {
    return;
  }
  for (std::map<Tool *, Worker *>::iterator iter = who_has_tool.begin();
       iter != who_has_tool.end(); ++iter) {
    if (iter->first == new_tool) {
      if (iter->second != NULL) {
        iter->second->removeTool(new_tool);
      }
      iter->second = this;
      return;
    }
  }
  who_has_tool.insert(std::pair<Tool *, Worker *>(new_tool, this));
}

void Worker::removeTool(Tool *tool) {
  if (tool == NULL) {
    std::cout << "Couldn't remove tool" << std::endl;
    return;
  }
  std::set<Tool *>::iterator tool_iter = tools.find(tool);
  if (tool_iter != tools.end()) {
    tools.erase(tool);
  }
  std::map<Tool *, Worker *>::iterator iter = who_has_tool.find(tool);
  if (iter != who_has_tool.end()) {
    iter->second = NULL;
  }
  for (std::set<Workshop *>::iterator iter = workshops.begin();
       iter != workshops.end(); ++iter) {
    ToolType type = (*iter)->getToolType();
    if (type == ToolType::HAMMER) {
      if (this->getTool<Hammer>() == NULL) {
        (*iter)->removeWorker(this);
        workshops.erase(*iter);
      } else {
        if (this->getTool<Shovel>() == NULL) {
          (*iter)->removeWorker(this);
          workshops.erase(*iter);
        }
      }
    }
  }
}

void Worker::useTool(Tool *tool) {
  std::cout << "Use Tool called" << std::endl;
  if (tool == NULL && tools.find(tool) == tools.end()) {
    std::cout << "Couldn't use tool because it's a skill issue" << std::endl;
    return;
  }
  tool->use();
}

void Worker::joinWorkshop(Workshop *workshop) {
  std::set<Workshop *>::iterator iter = workshops.find(workshop);
  if (iter != workshops.end()) {
    std::cout << "Already in this workshop" << std::endl;
    return;
  }
  if (workshop->registerWorker(this)) {
    workshops.insert(workshop);
  }
}

void Worker::leaveWorkshop(Workshop *workshop) { workshop->removeWorker(this); }

void Worker::removeWorkshop(Workshop *workshop) {
  std::set<Workshop *>::iterator iter = workshops.find(workshop);
  if (iter == workshops.end()) {
    std::cout << "Worker is not inside this workshop" << std::endl;
    return;
  }
  (*iter)->removeWorker(this);
  workshops.erase(*iter);
}

void Worker::work(Workshop *workshop) {
  if (workshops.find(workshop) == workshops.end()) {
    std::cout << "Worker is not in this workshop to work" << std::endl;
    return;
  }
  std::cout << "Working working working" << std::endl;
}
