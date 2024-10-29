#pragma once

#include "Employee.hpp"
#include <iostream>
#include <set>

class EmployeeManager {
  std::set<Employee *> employees;

public:
  EmployeeManager() : employees(std::set<Employee *>()) {}
  ~EmployeeManager() {}
  std::set<Employee *> &get_employees();
  void set_employees(std::set<Employee *> &employee_list) {
    employees = employee_list;
  }
  void addEmployee(Employee *employee) { employees.insert(employee); }
  void removeEmployee(Employee *employee) {
    std::set<Employee *>::iterator iter = employees.find(employee);
    employees.erase(iter);
  }
  void executeWorkday() {
    for (std::set<Employee *>::iterator iter = employees.begin();
         iter != employees.end(); ++iter) {
      (*iter)->executeWorkday();
    }
  }
  void calculatePayroll() {
    for (std::set<Employee *>::iterator iter = employees.begin();
         iter != employees.end(); ++iter) {
      int payment = (*iter)->calculate_paycheck();
      std::cout << "Employee: " << (*iter)->get_name() << " was paid "
                << payment << " guanza!!" << std::endl;
      ;
    }
  }
};
