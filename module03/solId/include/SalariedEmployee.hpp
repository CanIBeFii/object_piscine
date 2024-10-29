#pragma once

#include "Employee.hpp"
#include <memory>

class SalariedEmployee : public Employee {
protected:
  int days_worked;
  int hours_not_working;

public:
  SalariedEmployee() : Employee(), days_worked(0), hours_not_working(0) {}
  SalariedEmployee(int value, std::string &name_)
      : Employee(value, name_), days_worked(0), hours_not_working(0) {}
  ~SalariedEmployee() {}
  int get_days_worked() { return days_worked; }
  int get_hours_not_working() { return hours_not_working; }
  void set_days_worked(int days) { days_worked = days; }
  void set_hours_not_working(int hours) { hours_not_working = hours; }
  void emergency(int hours) { hours_not_working += hours; }
  virtual int executeWorkday() {
    days_worked += 1;
    return 1;
  }
  virtual int calculate_paycheck() {
    int working_hours = (days_worked * 7) - hours_not_working;
    if (working_hours < 0) {
      working_hours = 0;
    }
    int paycheck = working_hours * hourlyValue;
    days_worked = 0;
    hours_not_working = 0;
    return paycheck;
  }
};

class ContractWorker : public SalariedEmployee {
public:
  ContractWorker() : SalariedEmployee() {}
  ContractWorker(int value, std::string &name_)
      : SalariedEmployee(value, name_) {}
  ~ContractWorker() {}
};

class Apprentice : public SalariedEmployee {
  int hours_studying;

public:
  Apprentice() : SalariedEmployee(), hours_studying(0) {}
  Apprentice(int value, std::string &name_)
      : SalariedEmployee(value, name_), hours_studying(0) {}
  ~Apprentice() {}
  int get_hours_studying() { return hours_studying; }
  void set_hours_studying(int hours) { hours_studying = hours; }
  void study_hours(int hours) { hours_studying += hours; }
  int calculate_paycheck() {
    int working_hours = (days_worked * 7) - hours_not_working - hours_studying;
    if (working_hours < 0) {
      working_hours = 0;
    }
    int paycheck =
        working_hours * hourlyValue + hours_studying * hourlyValue / 2;
    days_worked = 0;
    hours_not_working = 0;
    hours_studying = 0;
    return paycheck;
  }
};
