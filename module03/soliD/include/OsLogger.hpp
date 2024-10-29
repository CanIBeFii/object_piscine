#pragma once

#include "ILogger.hpp"
#include <iostream>
#include <ostream>

class OsLogger : public ILogger {
  std::ostream &stream;

public:
  OsLogger(std::ostream &stream_) : stream(stream_) {}
  ~OsLogger() {}
  void write(std::string message) { stream << message << std::endl; }
};
