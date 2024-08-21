/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:39:50 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/19 14:09:45 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	AForm* s = someRandomIntern.makeForm("ShrubberyCreationForm","42");
	AForm* r = someRandomIntern.makeForm("RobotomyRequestForm", "hive");
	AForm* p = someRandomIntern.makeForm("PresidentialPardonForm", "Mickey Mouse");
	Bureaucrat b("Jerry", 72);

	std::cout << *s << std::endl;
	std::cout << *r << std::endl;
	std::cout << *p << std::endl;
	std::cout << b << std::endl;
	
	try
	{
		b.executeForm(*s);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	b.signForm(*s);
	
	try
	{
		b.executeForm(*s);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	b.signForm(*r);
	try
	{
		b.executeForm(*r);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	while (b.getGrade() > 45)
	{
		b.improveGrade();
	}
	std::cout << b << std::endl;
	try
	{
		for (int i = 0; i < 10; i++)
		{
			b.executeForm(*r);
		}
		Bureaucrat b1("President", 1);
		
		std::cout << b1 << std::endl;
		
		b1.signForm(*p);
		b1.executeForm(*p);
		for (int i = 0; i < 5; i++)
		{
			b1.lowerGrade();
		}
		std::cout << b1 << std::endl;
		b1.executeForm(*p);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	delete s;
	delete r;
	delete p;
	return (0);
}