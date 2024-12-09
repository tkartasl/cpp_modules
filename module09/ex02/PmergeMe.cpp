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

void PmergeMe::_validateNumberVector(std::string& arg) {
    if (arg.length() < 1)
        throw std::exception();
    for (char ch : arg) {
        if (std::isdigit(ch) == 0)
            throw std::exception();
    }
    int number = stoi(arg);
    for (int i : _numbers) {
        if (i == number) {
            throw std::exception();
        }  
    }
    _numbers.push_back(number);
}

bool PmergeMe::_validateInputVector() {
    size_t startPos = 0;
    size_t endPos = 0;
    std::string arg;

    try {
        while (endPos != std::string::npos) {
            endPos = _input.find(" ", startPos);
            if (endPos != std::string::npos) {
                arg = _input.substr(startPos, endPos - startPos);
                _validateNumberVector(arg);
                startPos = endPos + 1;
            }
        }
    } catch (std::exception& e) {
        return false;
    }
    return true;
}

void PmergeMe::_makePairsVector() {
    t_pair pair;
    int sizeOfVector = _numbers.size();

    for (int i = 0; (i + 1) < sizeOfVector; i += 2) {
        if (i < sizeOfVector) {
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
        _numberPairs.push_back(pair);
    }
    if (sizeOfVector % 2 != 0) {
        pair.small = _numbers[_numbers.size() - 1];
        pair.big = -1;
        _numberPairs.push_back(pair);
    } 
}

void PmergeMe::_mergeVector(int start, int middle, int end) {
    int sizeLeft = middle - start + 1;
    int sizeRight = end - middle;
    std::vector<int> left(sizeLeft);
    std::vector<int> right(sizeRight);


    for (int i = 0; i < sizeLeft; i++) {
        left[i] = _mainChain[start + i];
    }
    for (int j = 0; j < sizeRight; j++) {
        right[j] = _mainChain[middle + 1 + j];
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

void PmergeMe::_mergeSortVector(int start, int end) {
    if (start >= end)
        return;
    int middle = start + (end - start) / 2;
     _mergeSortVector(start, middle);
     _mergeSortVector(middle + 1, end);
     _mergeVector(start, middle, end);
}

int PmergeMe::_findPairVector(int& index) {
    int ret = 0;
   
    if (index >= (int)_sortedBigNumbers.size() && _numberPairs.size() > _sortedBigNumbers.size()) {
        return _numberPairs.back().small;
    }

    for (t_pair p : _numberPairs) {
        if (p.big == _sortedBigNumbers[index]) {
            ret = p.small;
            break;
        }
    }
    return ret;
}

int PmergeMe::_findIndexVector(int index) {
    if (index < 0 || index >= (int)_sortedBigNumbers.size()) {
        return -1;
    }

    for (size_t i = 0; i < _mainChain.size(); i++) {
        if (_sortedBigNumbers[index]  == _mainChain[i]) {
            return i;
        }
    }
    return -1;
}

void PmergeMe::_indexSmallNumbersVector(std::vector<int>& smallNumbers) {
    int size = _numberPairs.size();
    
    for (int i = 0; i < size; i++) {
        smallNumbers[i] = _findPairVector(i);
    }
}

int PmergeMe::_binarySearchVector(int& key, int low, int high) {
    if (high <= low)
        return (key > _mainChain[low]) ? (low + 1) : low;
    int mid = (low + high) / 2;

    if (key > _mainChain[mid])
        return _binarySearchVector(key, mid + 1, high);
    return _binarySearchVector(key, low, mid - 1);
}

void PmergeMe::_insertionSortVector() {
    int key;
    int position;
    int index = 1;
    int jacobIndex = 0;
    std::vector<int> smallNumbers(_numberPairs.size());
   
    _indexSmallNumbersVector(smallNumbers);
    int vecSize = smallNumbers.size();
    _mainChain.insert(_mainChain.begin(), smallNumbers[0]);

    for (int i = 1; i < vecSize; i++) {
        if (i < JACOBSTHAL_NUMBER_COUNT)
            jacobIndex = _jacobsthalNumbers[i] - 1;
        if (jacobIndex < vecSize) {
            key = smallNumbers[jacobIndex];
            index = _findIndexVector(jacobIndex);
            if (index == -1)
                throw std::out_of_range("index out of range");
            position = _binarySearchVector(key, 0, index);
            _mainChain.insert(_mainChain.begin() + position, key);
            for (int j = jacobIndex - 1; j >= _jacobsthalNumbers[i - 1]; j--) {
                key = smallNumbers[j];
                int idx = _findIndexVector(j);
                position = _binarySearchVector(key, 0, idx);
                _mainChain.insert(_mainChain.begin() + position, key);
            }
        }
        else {
            for (int k = _jacobsthalNumbers[i - 1]; k < vecSize; k++) {
                key = smallNumbers[k];
                position = _binarySearchVector(key, 0, _mainChain.size() - 1);
                _mainChain.insert(_mainChain.begin() + position, key);
            }
            break;
        }
    }
}

void PmergeMe::sortVector() {
    auto start = std::chrono::high_resolution_clock::now();
    if (!_validateInputVector()) {
        std::cerr << "Error: invalid input" << std::endl;
        return ;
    }
    try {
        _mainChain.reserve(_numbers.size());
        _makePairsVector();
        _mergeSortVector(0, _mainChain.size() - 1);
        _sortedBigNumbers = _mainChain;
        _insertionSortVector();
        auto end = std::chrono::high_resolution_clock::now();
        _durationVector = end - start;
    } catch (std::exception& e) {
        std::cerr << "Error" << std::endl;
    }
}

void PmergeMe::_validateNumberDeque(std::string& arg) {
    if (arg.length() < 1)
        throw std::exception();
    for (char ch : arg) {
        if (std::isdigit(ch) == 0)
            throw std::exception();
    }
    int number = stoi(arg);
    for (int i : _numbersDeque) {
        if (i == number) {
            throw std::exception();
        }  
    }
    _numbersDeque.push_back(number);
}

bool PmergeMe::_validateInputDeque() {
    size_t startPos = 0;
    size_t endPos = 0;
    std::string arg;

    try {
        while (endPos != std::string::npos) {
            endPos = _input.find(" ", startPos);
            if (endPos != std::string::npos) {
                arg = _input.substr(startPos, endPos - startPos);
                _validateNumberDeque(arg);
                 startPos = endPos + 1;
            }
        }
    } catch (std::exception& e) {
        return false;
    }
    return true;
}

void PmergeMe::_makePairsDeque() {
    t_pair pair;
    int sizeOfVector = _numbersDeque.size();

    for (int i = 0; (i + 1) < sizeOfVector; i += 2) {
        if (i < sizeOfVector) {
            if (_numbersDeque[i] < _numbersDeque[i + 1]) {
                pair.small = _numbersDeque[i];
                pair.big = _numbersDeque[i + 1];
            }
            else {
                pair.small = _numbersDeque[i + 1];
                pair.big = _numbersDeque[i];
            }
            _mainChainDeque.push_back(pair.big);
        }
        _numberPairsDeque.push_back(pair);
    }
    if (sizeOfVector % 2 != 0) {
        pair.small = _numbersDeque[_numbersDeque.size() - 1];
        pair.big = -1;
        _numberPairsDeque.push_back(pair);
    } 
}

void PmergeMe::_mergeDeque(int start, int middle, int end) {
    int sizeLeft = middle - start + 1;
    int sizeRight = end - middle;
    std::deque<int> left(sizeLeft);
    std::deque<int> right(sizeRight);


    for (int i = 0; i < sizeLeft; i++) {
        left[i] = _mainChainDeque[start + i];
    }
    for (int j = 0; j < sizeRight; j++) {
        right[j] = _mainChainDeque[middle + 1 + j];
    }

    int idxLeft = 0;
    int idxRight = 0;
    int i = start;

    while (idxLeft < sizeLeft && idxRight < sizeRight) {
        if (left[idxLeft] < right[idxRight]) {
            _mainChainDeque[i] = left[idxLeft];
            idxLeft++;
        }
        else {
            _mainChainDeque[i] = right[idxRight];
            idxRight++;
        }
        i++;
    }

    while (idxLeft < sizeLeft) {
        _mainChainDeque[i] = left[idxLeft];
        i++;
        idxLeft++;
    }
    while (idxRight < sizeRight) {
        _mainChainDeque[i] = right[idxRight];
        i++;
        idxRight++;
    }
}

void PmergeMe::_mergeSortDeque(int start, int end) {
    if (start >= end)
        return;
    int middle = start + (end - start) / 2;
     _mergeSortDeque(start, middle);
     _mergeSortDeque(middle + 1, end);
     _mergeDeque(start, middle, end);
}

int PmergeMe::_findPairDeque(int& index) {
    int ret = 0;
   
    if (index >= (int)_sortedBigNumbersDeque.size() && _numberPairsDeque.size() > _sortedBigNumbersDeque.size()) {
        return _numberPairsDeque.back().small;
    }

    for (t_pair p : _numberPairsDeque) {
        if (p.big == _sortedBigNumbersDeque[index]) {
            ret = p.small;
            break;
        }
    }
    return ret;
}

int PmergeMe::_findIndexDeque(int index) {
    if (index < 0 || index >= (int)_sortedBigNumbersDeque.size()) {
        return -1;
    }

    for (size_t i = 0; i < _mainChainDeque.size(); i++) {
        if (_sortedBigNumbersDeque[index]  == _mainChainDeque[i]) {
            return i;
        }
    }
    return -1;
}

void PmergeMe::_indexSmallNumbersDeque(std::deque<int>& smallNumbersDeque) {
    int size = _numberPairsDeque.size();
    
    for (int i = 0; i < size; i++) {
        smallNumbersDeque[i] = _findPairDeque(i);
    }
}

int PmergeMe::_binarySearchDeque(int& key, int low, int high) {
    if (high <= low)
        return (key > _mainChainDeque[low]) ? (low + 1) : low;
    int mid = (low + high) / 2;

    if (key > _mainChainDeque[mid])
        return _binarySearchDeque(key, mid + 1, high);
    return _binarySearchDeque(key, low, mid - 1);
}

void PmergeMe::_insertionSortDeque() {
    int key;
    int position;
    int index = 1;
    int jacobIndex = 0;
    std::deque<int> smallNumbersDeque(_numberPairsDeque.size());
   
    _indexSmallNumbersDeque(smallNumbersDeque);
    int dequeSize = smallNumbersDeque.size();
    _mainChainDeque.insert(_mainChainDeque.begin(), smallNumbersDeque[0]);

    for (int i = 1; i < dequeSize; i++) {
        if (i < JACOBSTHAL_NUMBER_COUNT)
            jacobIndex = _jacobsthalNumbers[i] - 1;
        if (jacobIndex < dequeSize) {
            key = smallNumbersDeque[jacobIndex];
            index = _findIndexDeque(jacobIndex);
            if (index == -1)
                throw std::out_of_range("index out of range");
            position = _binarySearchDeque(key, 0, index);
            _mainChainDeque.insert(_mainChainDeque.begin() + position, key);
            for (int j = jacobIndex - 1; j >= _jacobsthalNumbers[i - 1]; j--) {
                key = smallNumbersDeque[j];
                int idx = _findIndexDeque(j);
                position = _binarySearchDeque(key, 0, idx);
                _mainChainDeque.insert(_mainChainDeque.begin() + position, key);
            }
        }
        else {
            for (int k = _jacobsthalNumbers[i - 1]; k < dequeSize; k++) {
                key = smallNumbersDeque[k];
                position = _binarySearchDeque(key, 0, _mainChainDeque.size() - 1);
                _mainChainDeque.insert(_mainChainDeque.begin() + position, key);
            }
            break;
        }
    }
}

void PmergeMe::sortDeque() {
    auto start = std::chrono::high_resolution_clock::now();
    if (!_validateInputDeque()) {
        std::cerr << "Error: invalid input" << std::endl;
        return ;
    }
    try {
        _makePairsDeque();
        _mergeSortDeque(0, _mainChainDeque.size() - 1);
        _sortedBigNumbersDeque = _mainChainDeque;
        _insertionSortDeque();
        auto end = std::chrono::high_resolution_clock::now();
        _durationDeque = end - start;
    } catch (std::exception& e) {
        std::cerr << "Error" << std::endl;
    }
}

void PmergeMe::printResults() const {
    std::cout << "Before: ";
    
    for (int i : _numbers) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "After: ";
    for (int i : _mainChainDeque) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << _numbers.size()
    << " elements with std::vector : " << _durationVector.count() << " us" << std::endl;
    std::cout << "Time to process a range of " << _numbersDeque.size()
    << " elements with std::deque : " << _durationDeque.count() << " us" << std::endl;  

}