#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cerr << "Error: no arguments" << std::endl;
        return 1;
    }
    std::string input;
    for (int i = 1; i < argc; i++) {
        input += argv[i];
        input += " ";
    }
    PmergeMe pm(input);
    pm.sort();
	return 0;
}