#pragma once

#include "ILogger.hpp"
#include <ctime>

class HeaderLogger : public ILogger {
  ILogger *logger;

public:
  HeaderLogger(ILogger *logger_) : logger(logger_) {}
  ~HeaderLogger() {}
  void write(std::string message) {
    char buffer[20];
    std::time_t now = std::time(nullptr);
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S",
                  std::localtime(&now));
    std::string time(buffer);
    std::string spacer(" -> ");
    logger->write(message + spacer + time);
  }
};
