#pragma once

#include <string>

class Employee {
protected:
  int hourlyValue;
  std::string name;

public:
  Employee() : hourlyValue(0) {};
  Employee(int value, std::string &name_) : hourlyValue(value), name(name_) {}
  ~Employee() {};
  int get_hourly_value() { return hourlyValue; }
  std::string &get_name() { return name; }
  void set_hourly_value(int value) { hourlyValue = value; }
  void set_name(std::string name_) { name = name_; }
  virtual int executeWorkday() = 0;
  virtual int calculate_paycheck() = 0;
};
