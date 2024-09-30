/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:53:54 by tkartasl          #+#    #+#             */
/*   Updated: 2024/09/30 13:19:02 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <random>
#include <iostream>

Base* generate(void)
{
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 3);
	
	int	nbr = dis(gen);
	
	switch (nbr)
	{
		case 1:
			std::cout << "Generated A" << std::endl;
			return new A();
		case 2:
			std::cout << "Generated B" << std::endl;
			return new B();
		case 3:
			std::cout << "Generated C" << std::endl;
			return new C();
	}
	return nullptr;	
}

void	identify(Base* p)
{
	A* a = dynamic_cast<A *>(p);
	if (a)
	{
		std::cout << "A" << std::endl;
		return;
	}
	B* b = dynamic_cast<B *>(p);
	if (b)
	{
		std::cout << "B" << std::endl;
		return;
	}
	C* c = dynamic_cast<C *>(p);
	if (c)
		std::cout << "C" << std::endl;		
}

void	identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)a;
		return;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B& b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		(void)b;
		return;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C& c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		(void)c;
		return;
	}
	catch(const std::exception& e)
	{
	}
}

int main()
{
	Base* p = generate();
	identify(p);
	identify(*p);
	delete p;
	for (int i = 0; i < 10; i++)
	{
		p = generate();
		identify(p);
		identify(*p);
		delete p;
	}

	return (0);
}