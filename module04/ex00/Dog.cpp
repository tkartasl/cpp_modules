/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:49:32 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/27 09:57:15 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog's constructor called" << std::endl;
	this->_type = "Dog";
	return;
}

Dog::Dog(Dog const& src) : Animal(src)
{
	std::cout << "Dog's copy constructor called" << std::endl;
	return;
}

Dog::~Dog(void)
{
	std::cout << "Dog's destructor called" << std::endl;
	return;
}

Dog& Dog::operator=(Dog const& src)
{
	if (this != &src)
		Animal::operator=(src);
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Wuf wuf" << std::endl;
}
