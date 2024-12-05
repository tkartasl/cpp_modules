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
        throw std::exception();
    for (char ch : arg) {
        if (std::isdigit(ch) == 0)
            throw std::exception();
    }
    int number = stoi(arg);
    for (int i : _numbers) {
		if (i == number)
			throw std::exception();
	}
	_numbers.push_back(number);
}

bool PmergeMe::_validateInput() {
    int startPos = 0;
    int endPos = 0;
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

void PmergeMe::_printBefore() {
	std::cout << "Before: ";
	for (int i : _numbers) {
		std::cout << i;
	}
	std::cout << std::endl;
}

void PmergeMe::_makePairs() {
	t_pair pair;
	int sizeOfVector = _numbers.size();

	for (int i = 0; i < sizeOfVector; i++) {
		if (i + 1 < sizeOfVector) {
			if (_numbers[i] < _numbers[i + 1]) {
				pair.small = _numbers[i];
				pair.big = _numbers[i + 1];
			}
			else {
				pair.small = _numbers[i + 1];
				pair.big = _numbers[i];
			}
			_mainChain.push_back(pair.big);
		}
		else {
			pair.small = _numbers[i];
			pair.big = -1;
		}
		_numberPairs.push_back(pair);
	}
}

void PmergeMe::_merge(int start, int middle, int end) {
	std::vector<int> left;
	std::vector<int> right;
	int sizeLeft = middle - start + 1;
	int sizeRight = end - middle;
	
	for (int i = 0; i < sizeLeft; i++) {
		left[i] = _mainChain[start + i];
	}
	for (int j = 0; j < sizeRight; j++) {
		right[j] = right[middle + 1 + j];
	}

	int idxLeft = 0;
	int idxRight = 0;
	int i = start;

	while (idxLeft < sizeLeft && idxRight < sizeRight) {
		if (left[idxLeft] < right[idxRight]) {
			_mainChain[i] = left[idxLeft];
			idxLeft++;
		}
		else {
			_mainChain[i] = right[idxRight];
			idxRight++;
		}
		i++;
	}

	while (idxLeft < sizeLeft) {
		_mainChain[i] = left[idxLeft];
		i++;
		idxLeft++;
	}
	while (idxRight < sizeRight) {
		_mainChain[i] = right[idxRight];
		i++;
		idxRight++;
	}
}

void PmergeMe::_mergeSort(int start, int end) {
	if (start > end)
		return;
	int middle = (start + end) / 2;
	_mergeSort(start, middle);
	_mergeSort(middle + 1, end);
	_merge(start, middle, end);
}

void PmergeMe::_insertionSort() {
	
}

void PmergeMe::sort() {
    if (!_validateInput()) {
        std::cerr << "Error: invalid input" << std::endl;
        return ;
    }
	_printBefore();
    _makePairs();
	_mergeSort(0, _mainChain.size() - 1);
	_insertionSort();
}