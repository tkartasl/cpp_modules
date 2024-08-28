/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:11:36 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/28 12:32:42 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
	std::cout << "WrongAnimal's constructor called" << std::endl;
	return;
}
	
WrongAnimal::WrongAnimal(WrongAnimal const& src)
{
	std::cout << "WrongAnimal's copy constructor called" << std::endl;
	this->_type = src._type;
	return;
}
	
WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal's destructor called" << std::endl;
	return;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const &src)
{
	if (this != &src)
		this->_type = src._type;
	return *this;
}

std::string WrongAnimal::getType(void) const
{
	return this->_type;
}
void WrongAnimal::makeSound(void) const
{
	std::cout << "Generic wronganimal sound" << std::endl;
}