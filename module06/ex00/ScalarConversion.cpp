/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:55:49 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/21 10:57:23 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"
#include <iostream>
#include <limits>

ScalarConversion::ScalarConversion(void)
{
	return;
}

ScalarConversion::ScalarConversion(ScalarConversion const& src)
{
	(void)src;
	return;
}

ScalarConversion::~ScalarConversion(void)
{
	return;
}

ScalarConversion& ScalarConversion::operator=(ScalarConversion const& src)
{
	(void)src;
	return *this;
}

void ScalarConversion::convert(std::string string)
{
	try
	{
		if (std::isdigit(string[0]) && string.find('.') != std::string::npos && string.find('f') != std::string::npos)
		{
			float f = stof(string);
		}
		else if (std::isdigit(string[0]) && string.find('.') != std::string::npos)
		{
			double d = stod(string);
		}
		else if (std::isdigit(string[0]) || (string[0] == '-' && string.length() > 1))
		{
			int	i = stoi(string);
		}
		else
			char c = string[0];
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	

}