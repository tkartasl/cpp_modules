#include "EasyFind.hpp"
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> v = {0, 1, 5, 6, 3, 202020};
	if (easyfind(v, 5) != v.end())
		std::cout << "Found 5" << std::endl;
	else
		std::cout << "Not found\n";
	easyfind(v, 100);

	return 0;
}