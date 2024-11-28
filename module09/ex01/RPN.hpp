#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <stack>

class RPN {
    public:
        RPN(std::string);
        ~RPN();
        RPN(RPN const&);
        RPN& operator=(RPN const&);

        void calculate();
    private:
        std::string _args;
        std::stack<int> _stack;
        void _splitInput();
        bool _validateArgument(std::string&);
        bool _performOperation(std::string&);

};

#endif