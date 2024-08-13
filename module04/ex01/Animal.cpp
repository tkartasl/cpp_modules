/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:32:54 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/13 12:31:46 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << "Animal's constructor called" << std::endl;
	return;
}
	
Animal::Animal(Animal const& src)
{
	std::cout << "Animal's copy constructor called" << std::endl;
	this->_type = src._type;
	return;
}
	
Animal::~Animal(void)
{
	std::cout << "Animal's destructor called" << std::endl;
	return;
}

Animal& Animal::operator=(Animal const &src)
{
	if (this != &src)
		this->_type = src._type;
	return *this;	
}

std::string Animal::getType(void) const
{
	return this->_type;
}
void Animal::makeSound(void) const
{
	std::cout << "Generic animal sound" << std::endl;
}
	