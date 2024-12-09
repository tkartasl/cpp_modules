#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <vector>
# include <deque>
# include <chrono>
# define JACOBSTHAL_NUMBER_COUNT 18

typedef struct s_pair {
	int small;
	int big;
} t_pair;

class PmergeMe
{
    public:
        PmergeMe(std::string&);
        ~PmergeMe();
        PmergeMe(PmergeMe const&);
        PmergeMe& operator=(PmergeMe const&);

        void sortVector();
        void sortDeque();
        void printResults() const;
    private:
        std::string _input;
        bool _validateInputVector();
        void _validateNumberVector(std::string&);
        void _printUnsortedVector();
        void _printSortedVector();
        void _makePairsVector();
        void _mergeSortVector(int, int);
        void _insertionSortVector();
        void _mergeVector(int, int, int);
        int _binarySearchVector(int&, int, int);
        void _indexSmallNumbersVector(std::vector<int>&);
        int _findIndexVector(int);
        int _findPairVector(int&);
        bool _validateInputDeque();
        void _validateNumberDeque(std::string&);
        void _printUnsortedDeque();
        void _printSortedDeque();
        void _makePairsDeque();
        void _mergeSortDeque(int, int);
        void _insertionSortDeque();
        void _mergeDeque(int, int, int);
        int _binarySearchDeque(int&, int, int);
        void _indexSmallNumbersDeque(std::deque<int>&);
        int _findIndexDeque(int);
        int _findPairDeque(int&);
        std::vector<int> _numbers;
        std::vector<t_pair> _numberPairs;
        std::vector<int> _mainChain;
        std::vector<int> _sortedBigNumbers;
        std::deque<int> _numbersDeque;
        std::deque<t_pair> _numberPairsDeque;
        std::deque<int> _mainChainDeque;
        std::deque<int> _sortedBigNumbersDeque;
        std::chrono::duration<double, std::micro> _durationVector;
        std::chrono::duration<double, std::micro> _durationDeque;
        int _jacobsthalNumbers[JACOBSTHAL_NUMBER_COUNT] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763};
};

#endif
