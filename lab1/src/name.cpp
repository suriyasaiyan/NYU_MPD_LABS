#include <iostream>
#include "name.hpp"

std::string askForName() {
    std::string name;
    std::cout << "Please enter your name: ";
    std::cin >> name;
    return name;
}
