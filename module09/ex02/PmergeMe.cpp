#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::string& input) : _input(input) {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const& src) {
    this->_input = src._input;
}

PmergeMe& PmergeMe::operator=(PmergeMe const& src) {
    if (this != &src)
        this->_input = src._input;
    return *this;
}

void PmergeMe::_validateNumber(std::string& arg) {
    if (arg.length() < 1)
        throw std::exception;
    for (char ch : arg) {
        if (std::isdigit(ch) == 0)
            throw std::exception;
    }
    int number = stoi(arg);
    _numbers.push_back(number);
}

bool PmergeMe::_validateInput() {
    size_t startPos = 0;
    size_t endPos = 0;
    std::string arg;

    try {
        while (endPos != std::string::npos) {
            endPos = _input.find(" ", startPos);
            if (endPos != std::string::npos) {
                arg = _input.substr(startPos, endPos - startPos);
                _validateNumber(arg);
                 startPos = endPos + 1;
            }
        }
    } catch (std::exception& e) {
        return false;
    }
    return true;
}

void PmergeMe::sort() {
    if (!_validateInput()) {
        std::cerr << "Error: invalid input" << std::endl;
        return ;
    }
    
}