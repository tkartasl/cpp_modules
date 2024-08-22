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
#include <iomanip>

int	detectType(std::string string)
{
	if ((string.find('.') != std::string::npos && string.find('f') != std::string::npos)
		|| string == "-inff" || string == "inff" || string == "nanf")
		return 0;
	else if ((string.find('.') != std::string::npos && string.length() > 1)
		|| string == "-inf" || string == "inf" || string == "nan")
	{
		return 1;
	}
	else if (std::isdigit(string[0]) || (string[0] == '-' && string.length() > 1))
	{
		return 2;
	}
	else
		return 3;
}

void toFloat(std::string string)
{
	float f = 0;
	if (string == "-inff" || string == "inff" || string == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << string << std::endl;
		string.pop_back();
		std::cout << "double: " << string << std::endl;
		return;
	}

	try
	{
		f = stof(string);
	}
	catch(const std::exception& e)
	{
		std::cout << "type conversion is impossible" << std::endl;
		return;
	}

	if (f < 32 || f > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	
	if (f < std::numeric_limits<int>::min() || static_cast<double>(f) > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void toDouble(std::string string)
{
	double d = 0;
	if (string == "-inf" || string == "inf" || string == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << (string + "f") << std::endl;
		std::cout << "double: " << string << std::endl;
		return;
	}

	try
	{
		d = stod(string);
	}
	catch(const std::exception& e)
	{
		std::cout << "type conversion is impossible" << std::endl;
		return;
	}
	if (d < 32 || d > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	
	std::cout << "float: " << std::fixed << std::setprecision(1);
	std::cout << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void toInt(std::string string)
{
	int	i = 0;

	try
	{
		i = stoi(string);
	}
	catch(const std::exception& e)
	{
		std::cout << " type conversion impossible" << std::endl;
		return;
	}
	if (i < 32 || i > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1);
	std::cout << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void toChar(std::string string)
{
	char c = static_cast<char>(string[0]);

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;	
}

void ScalarConversion::convert(std::string string)
{
	int	type = detectType(string);

	switch(type)
	{
		case 0:
			toFloat(string);
			break;
		case 1:
			toDouble(string);
			break;
		case 2:
			toInt(string);
			break;
		case 3:
			toChar(string);
	}
}