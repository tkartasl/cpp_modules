/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:54:19 by tkartasl          #+#    #+#             */
/*   Updated: 2024/09/02 15:42:16 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main()
{
	Array<int> a(10);
	Array<std::string> str(3);
	int t = 0;
	
	str[0] = "Hello";
	str[1] = "world";
	str[2] = "!!!";

	//printing empty array
	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << std::endl;

	//printing sizes of arrays
	std::cout << "size of a: " << a.size() << std::endl;
	std::cout << "size of str: " << str.size() << std::endl;
	
	for (int i = 0; i < 10; i++)
	{
		a[i] = t++;
	}
	//copy a to b
	Array<int> b(a);
	std::cout << "a & b after copy" << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << "a: " << a[i] << " " << "b: " << b[i] << std::endl;
	
	//change b
	for (int i = 0; i < 10; i++)
	{
		b[i] *= 2;
	}
	std::cout << "a & b after changing b" << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << "a: " << a[i] << " " << "b: " << b[i] << std::endl;
	std::cout << std::endl;
	a[0] = 99;
	std::cout << a[0] << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << str[i] << std::endl;
	
	try
	{
		std::cout << a[11];
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << a[-11];
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}