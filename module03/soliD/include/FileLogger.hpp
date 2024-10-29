#include "ILogger.hpp"
#include <fstream>

class FileLogger : public ILogger {
  std::fstream file;
  std::string &filename;

public:
  FileLogger(std::string &filename_)
      : filename(filename_),
        file(std::fstream(filename_, std::fstream::out | std::fstream::app)) {}
  ~FileLogger() {};
  void write(std::string message) {
    if (!file.is_open()) {
      file = std::fstream(filename, std::fstream::out | std::fstream::app);
    }
    file.write(message.c_str(), message.size());
  }
};
