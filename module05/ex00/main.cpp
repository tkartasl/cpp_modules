/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:39:50 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/15 14:04:03 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b("Pekka", 150);
	try
	{
		std::cout << b.getGrade() << std::endl;
		b.improveGrade();
		std::cout << b.getGrade() << std::endl;
		b.lowerGrade();
		std::cout << b.getGrade() << std::endl;
		b.lowerGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat c("Jorma", 250000);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat c("Jorma", -5000);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat d("Seppo", 3);
		std::cout << d << std::endl;
		d.improveGrade();
		std::cout << d << std::endl;
		d.improveGrade();
		std::cout << d << std::endl;
		d.improveGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}