#include <string>
#include <iostream>
#include "color.hh"

class Logger {
    public:
        static void success(const std::string msg);
        static void status(const std::string msg);
        static void debug(const std::string msg);
        static void error(const std::string msg);
};