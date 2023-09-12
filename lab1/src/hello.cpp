#include <iostream>
#include "name.hpp"

int main() {
    std::string userName = askForName();
    std::cout << "Hello, " << userName << "!" << std::endl;
    return 0;
}
