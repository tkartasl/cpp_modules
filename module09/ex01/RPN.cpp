#include "RPN.hpp"

RPN::RPN(std::string args) : _args(args) {}

RPN::~RPN() {}

RPN::RPN(RPN const& src) {
    this->_args = src._args;
    this->_stack = src._stack;
}

RPN& RPN::operator=(RPN const& src) {
    if (this != &src) {
        this->_args = src._args;
        this->_stack = src._stack;
    }
    return *this;
}

void RPN::calculate() {
    try {
        _splitInput();
    } catch (std::exception& e) {
        throw;
    }
}

bool RPN::_validateArgument(std::string& arg) {
	if (arg.length() < 1)
		return false;
	if ((arg == "-" || arg == "+" || arg == "/" || arg == "*") && _stack.size() > 1)
		return true;
	for (size_t i = 0; i < arg.length(); i++) {
		if (!std::isdigit(arg[i]))
			return false; 
	}

	return true;
}

bool RPN::_performOperation(std::string& arg) {
    int first;
    int second;

    try {
        if (!_validateArgument(arg)) {
            std::cerr << "Error" << std::endl;
            return false;
        }
        switch(arg[0]) {
            case '-':
                first = _stack.top();
                _stack.pop();
                second = _stack.top();
                _stack.pop();
                _stack.push(second - first);
                break;
             case '+':
                first = _stack.top();
                _stack.pop();
                second = _stack.top();
                _stack.pop();
                _stack.push(second + first);
                break;
             case '/':
                 first = _stack.top();
                _stack.pop();
                second = _stack.top();
                _stack.pop();
                _stack.push(second / first);
                break;
             case '*':
                 first = _stack.top();
                _stack.pop();
                second = _stack.top();
                _stack.pop();
                _stack.push(second * first);
                break;
            default:
                int number = stoi(arg);
                _stack.push(number);
        }
    } catch (std::exception& e) {
        throw;
    }
    return true;
}

void RPN::_splitInput() {
    std::string arg;
    size_t start = 0;
    size_t delimiter = 0;
    try {
        while (delimiter != std::string::npos) {
            delimiter = _args.find(" ", start);
            if (delimiter != std::string::npos)
                arg = _args.substr(start, delimiter - start);
            else
                arg = _args.substr(start, _args.length() - start);
            start = delimiter + 1;
            if (!_performOperation(arg))
                return;
        }
        if (_stack.size() > 1) {
            std::cerr << "Error" << std::endl;
            return;
        }
        std::cout << _stack.top() << std::endl;
    } catch (std::exception& e) {
        throw;
    }
}
