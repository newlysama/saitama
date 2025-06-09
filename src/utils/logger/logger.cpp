#include "logger.hh"

void Logger::success(const std::string msg) {
    std::cout << GREEN << "[SUCCESS] " << msg << RESET;
}

void Logger::status(const std::string msg) {
    std::cout << YELLOW << "[STATUS] " << msg << RESET;
}

void Logger::debug(const std::string msg) {
    std::cout << CYAN << "[DEBUG] " << msg << RESET;
}

void Logger::error(const std::string msg) {
    std::cout << RED << "[ERROR] " << msg << RESET;
}

void Logger::def(const std::string msg) {
    std::cout << "[DEFAULT] " << msg;
}