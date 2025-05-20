#include "../include/Harl.hpp"

void Harl::debug(void) {
    std::cout << DEBUG_MSG << std::endl;
}

void Harl::info(void) {
    std::cout << INFO_MSG << std::endl;
}

void Harl::warning(void) {
    std::cout << WARNING_MSG << std::endl;
}

void Harl::error(void) {
    std::cout << ERROR_MSG << std::endl;
}

void Harl::complain(std::string level) {
    typedef void (Harl::*HarlFunc)(void);

    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    HarlFunc functions[4] = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    for (int i = 0; i < 4; ++i) {
        if (levels[i] == level) {
            (this->*functions[i])();
            return;
        }
    }

    std::cout << "Unknown level: " << level << std::endl;
}
