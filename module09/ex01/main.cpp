#include "RPN.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Wrong amount of arguments (1 required)" << std::endl;
        return 1;
    }
    RPN reverseMath(argv[1]);
    try {
        reverseMath.calculate();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}