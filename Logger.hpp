#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <fstream>

/* To start with empty file, call std::ofstream ofs("log.txt"); + ofs.close(); at the start of program. */

class Logger {
public:
  Logger() = delete;

  static std::string getCurrentDateTime() {
    std::time_t t = std::time(nullptr);
    char stringBuffer[100];
    std::strftime(stringBuffer, sizeof(stringBuffer), "%Y/%m/%d %X", std::localtime(&t));

    return std::string(stringBuffer);
  }

  static void log(const char* type, const std::string& message) {
    std::ofstream ofs("log.txt", std::ios_base::out |  std::ios_base::app);
    ofs << getCurrentDateTime() << ' ' << type << '\t'<< message << std::endl;
    ofs.close();
  }
};

#endif
