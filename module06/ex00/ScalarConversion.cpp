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

ScalarConversion::ScalarConversion(void) {}
ScalarConversion::ScalarConversion(ScalarConversion const&) {}
ScalarConversion::~ScalarConversion(void) {}
ScalarConversion& ScalarConversion::operator=(ScalarConversion const& src)
{
	(void)src;
	return *this;
}

bool verifyNumber(std::string string)
{
	int dotCounter = 0;
	if (string.back() == 'f')
		string.pop_back();
	if (string[0] != '-' && isdigit(string[0] == 0))
		return false;
	for (size_t i = 1; i < string.length(); i++)
	{
		if (string[i] == '.')
			dotCounter++;
		if ((isdigit(string[i]) == 0 && string[i] != '.') || dotCounter > 1)
			return false;
	}
	return true;
}

int	detectType(std::string string)
{
	if ((string.find('.') != std::string::npos && string.back() == 'f')
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

	try
	{
		f = stof(string);
	}
	catch(const std::exception& e)
	{
		std::cout << "type conversion is impossible" << std::endl;
		return;
	}
	if (string == "-inff" || string == "inff" || string == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
		return;
	}
	if (verifyNumber(string) == false)
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

	try
	{
		d = stod(string);
	}
	catch(const std::exception& e)
	{
		std::cout << "type conversion is impossible" << std::endl;
		return;
	}
	if (string == "-inf" || string == "inf" || string == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
		return;
	}
	if (verifyNumber(string) == false)
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

	if (verifyNumber(string) == false)
	{
		std::cout << "type conversion is impossible" << std::endl;
		return;
	}
	try
	{
		i = stoi(string);
	}
	catch(const std::exception& e)
	{
		std::cout << " type conversion is impossible" << std::endl;
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
	if (string.length() > 1)
	{
		std::cout << "type conversion is impossible" << std::endl;
		return;
	}

	char c = static_cast<char>(string[0]);

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;	
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