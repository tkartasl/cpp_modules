/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:39:50 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/29 14:37:19 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat b("Pekka", 50);
	Form f("complain", 50, 50);
	Form f1("Autograph", 1, 1);
	b.signForm(f1);
	try
	{
		std::cout << f << std::endl;
		std::cout << b << std::endl;
		b.signForm(f);
		std::cout << "Is the form signed? 1 if true, 0 if false: " << f.isSigned() << std::endl;
		b.lowerGrade();
		std::cout << b << std::endl;
		b.signForm(f1);
		std::cout << "Is the form signed? 1 if true, 0 if false: " << f.isSigned() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		Form f2("fail", 0, 1);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form f2("fail", 1, 100000);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}