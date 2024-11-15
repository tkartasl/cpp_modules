#include "MutantStack.hpp"
#include <stack>
#include <iostream>
#include <list>

template <typename T>
void printStack(MutantStack<T> element) {
	typename MutantStack<T>::iterator it = element.begin();
	typename MutantStack<T>::iterator ite = element.end();
	++it;
	--it;
	std::cout << "elements:\n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "MutantStack:\n";
	std::cout << "top of stack " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size of stack " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "elements:\n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "\n\n";
	{
		std::cout << "std::list:\n";
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << "top of stack " << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << "size of stack " << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "elements:\n";
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		};
		std::cout << "\n\n";
	}
	{
		MutantStack<std::string> stack_a;
		MutantStack<std::string> stack_b;

		stack_a.push("hei");
		stack_a.push("moi");
		stack_a.push("jee");
		stack_a.push("wazaaaaa");
		stack_b.push("alohaa");
		stack_b.push("omg");
		stack_b.push("Hello world");

		std::cout << "size of a stack before swap " << stack_a.size() << std::endl;
		std::cout << "size of b stack before swap " << stack_b.size() << std::endl;
		
		std::cout << "\n\n";

		std::cout << "Stack content before swap:\n";
		printStack(stack_a);
		std::cout << "-------\n";
		printStack(stack_b);
		stack_a.swap(stack_b);

		std::cout << "\n\n";

		std::cout << "size of a stack after swap " << stack_a.size() << std::endl;
		std::cout << "size of b stack after swap " << stack_b.size() << std::endl;
		std::cout << "\n\n";
		std::cout << "Stack content after swap:\n";
		printStack(stack_a);
		std::cout << "-------\n";
		printStack(stack_b);
	}
	return 0;
}