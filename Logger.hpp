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

  static void log(const std::string& type, const std::string& message) {
    std::string file = "log.txt";
    std::string dateTime = getCurrentDateTime();
    std::ofstream ofs(file.c_str(), std::ios_base::out | std::ios_base::app);

    ofs << dateTime << ' ' << type << '\t'<< message << std::endl;
    ofs.close();
  }
};

#endif
