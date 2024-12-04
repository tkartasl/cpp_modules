#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <vector>

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
        std::vector<int> _numbers;
};

#endif
