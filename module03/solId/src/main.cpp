#include "EmployeeManager.hpp"
#include "HourlyEmployee.hpp"
#include "SalariedEmployee.hpp"

int main() {
  EmployeeManager manager;

  std::string name("Jack Daniel's");
  TempWorker temp(50, name);
  std::string name1("Emanuel Jackson");
  ContractWorker worker(100, name1);
  std::string name2("Lily WompWomp");
  Apprentice aprrentice(100, name2);

  manager.addEmployee(&temp);
  manager.addEmployee(&worker);
  manager.addEmployee(&aprrentice);

  manager.executeWorkday();
  manager.calculatePayroll();
  manager.executeWorkday();
  temp.mobilize(5);
  worker.emergency(6);
  aprrentice.emergency(6);
  aprrentice.study_hours(5);
  manager.calculatePayroll();
  return 0;
}
