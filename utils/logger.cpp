#include "logger.hh"

void Logger::success(const std::string msg) {
    std::cout << GREEN << msg << RESET << "\n";
}

void Logger::status(const std::string msg) {
    std::cout << YELLOW << msg << RESET << "\n";
}

void Logger::debug(const std::string msg) {
    std::cout << CYAN << msg << RESET << "\n";
}

void Logger::error(const std::string msg) {
    std::cout << RED << msg << RESET << "\n";
}