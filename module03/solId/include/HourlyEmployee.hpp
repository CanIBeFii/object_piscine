#pragma once

#include "Employee.hpp"

class HourlyEmployee : public Employee {
protected:
  int hours_worked;

public:
  HourlyEmployee() : Employee(), hours_worked(0) {}
  HourlyEmployee(int value, std::string &name_)
      : Employee(value, name_), hours_worked(0) {}
  ~HourlyEmployee() {}
  int get_hours_worked() { return hours_worked; }
  void set_hours_worked(int hours) { hours_worked = hours; }
  virtual int executeWorkday() {
    hours_worked += 7;
    return 7;
  }
  virtual int calculate_paycheck() {
    int hours = hours_worked;
    hours_worked = 0;
    return hours * hourlyValue;
  }
};

class TempWorker : public HourlyEmployee {
public:
  TempWorker() : HourlyEmployee() {}
  TempWorker(int value, std::string &name_) : HourlyEmployee(value, name_) {}
  ~TempWorker() {}
  void mobilize(int hours) { hours_worked += hours; }
};
