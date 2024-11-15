#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H
# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack() : std::stack<T>() {};
		~MutantStack<T>() {};
		MutantStack<T>(MutantStack<T> const& src) : std::stack<T>(src) {}
		MutantStack<T>& operator=(MutantStack<T> const& src) {
			if (this != &src) {
				std::stack<T>::operator=(src);
			}
			return *this;
		}

		using iterator = typename std::stack<T>::container_type::iterator;
    	using const_iterator = typename std::stack<T>::container_type::const_iterator;

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
		const_iterator begin() const { return this->c.begin(); }
		const_iterator end() const { return this->c.end(); }
};

#endif
