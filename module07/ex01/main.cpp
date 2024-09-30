/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:59:05 by tkartasl          #+#    #+#             */
/*   Updated: 2024/09/30 14:42:26 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template<typename T>
void add(T& a)
{
	a++;
};

template<typename T>
void print(T& a)
{
	std::cout << a << std::endl;
};

int main()
{ 
	int intArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	char charArray[5] = {'a', 'b', 'c', 'd', 'e'};
	std::string stringArray[3] = {"Hello", "world", "!!!"};
	const int cintArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	const char ccharArray[5] = {'a', 'b', 'c', 'd', 'e'};

	
	std::cout << "Before function template call:" << std::endl;
	
	iter(intArray, 10, print);
	iter(intArray, 10, add);
	
	std::cout << "\n" << "After function template call:" << std::endl;
	iter(intArray, 10, print);
	
	std::cout << "\n" << "Before function template call:" << std::endl;
	iter(charArray, 5, print);
	
	iter(charArray, 5, add);
	
	std::cout << "\n" << "After function template call:" << std::endl;
	iter(charArray, 5, print);

	std::cout << std::endl;
	iter(stringArray, 3, print);

	const std::string constArray[3] = {"Hello", "world", "!!!"};
	iter(constArray, 3, print);

	std::cout << "\n" << "Const int Array template call:" << std::endl;
	iter(cintArray, 10, print);
	
	std::cout << "\n" << "Const char Array template call:" << std::endl;
	iter(ccharArray, 5, print);

	return 0;
}