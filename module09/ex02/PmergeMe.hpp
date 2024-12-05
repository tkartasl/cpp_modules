#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <vector>

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

        void sort();
    private:
        std::string _input;
        bool _validateInput();
        void _validateNumber(std::string&);
		void _printBefore();
		void _makePairs();
		void _mergeSort(int, int);
		void _insertionSort();
		void _merge(int, int, int);
        std::vector<int> _numbers;
		std::vector<t_pair> _numberPairs;
		std::vector<int> _mainChain;
};

#endif
