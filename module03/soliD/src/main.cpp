#include "FileLogger.hpp"
#include "HeaderLogger.hpp"
#include "OsLogger.hpp"
#include <string>
#include <vector>

int main() {
  std::string file("/home/fii/Desktop/object_piscine/module03/soliD/file");
  FileLogger filelog(file);
  OsLogger oslog(std::cout);
  HeaderLogger headerOs(&oslog);
  HeaderLogger headerFile(&filelog);

  std::vector<ILogger *> logs;
  logs.push_back(&filelog);
  logs.push_back(&oslog);
  logs.push_back(&headerOs);
  logs.push_back(&headerFile);

  std::vector<std::string> strings;
  strings.push_back(std::string("OLA"));
  strings.push_back(std::string("amigos"));
  strings.push_back(std::string("j´a estamos aqui"));
  strings.push_back(std::string("chegou a hora yeah yeah"));
  strings.push_back(
      std::string("Adeus vou ter de me ir embora infelizmente :((("));
  strings.push_back(std::string("I will miss you <3"));

  for (std::vector<std::string>::iterator iter = strings.begin();
       iter != strings.end(); ++iter) {
    for (std::vector<ILogger *>::iterator iter_logs = logs.begin();
         iter_logs != logs.end(); ++iter_logs) {
      (*iter_logs)->write(*iter);
    }
  }
  return 0;
}
