#include "EasyFind.hpp"
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> v = {0, 1, 5, 6, 3, 202020};
	try
	{
		for (auto it = v.begin(); it < v.end(); it++) {
			easyfind(v, *it);
		}
		easyfind(v, 100);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	//std::cout << "answer value and location in memory " << answer << std::endl;
	return 0;
}