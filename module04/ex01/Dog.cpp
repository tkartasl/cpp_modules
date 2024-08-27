/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:49:32 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/27 10:02:00 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog's constructor called" << std::endl;
	this->_type = "Dog";
	this->_brainPTR = new Brain();
	return;
}

Dog::Dog(Dog const& src) : Animal(src)
{
	std::cout << "Dog's copy constructor called" << std::endl;
	this->_brainPTR = new Brain(*src._brainPTR);
	return;
}

Dog::~Dog(void)
{
	std::cout << "Dog's destructor called" << std::endl;
	delete _brainPTR;
	return;
}

Dog& Dog::operator=(Dog const& src)
{
	if (this != &src)
	{
		Animal::operator=(src);
		this->_brainPTR = new Brain(*src._brainPTR);
	}
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Wuf wuf" << std::endl;
}

Brain* Dog::getBrains(void) const
{
	return this->_brainPTR;
}
