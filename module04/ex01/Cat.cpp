/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:45:21 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/27 10:00:10 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat's constructor called" << std::endl;
	this->_type = "Cat";
	this->_brainPTR = new Brain();
	return;
}

Cat::Cat(Cat const& src) : Animal(src)
{
	std::cout << "Cat's constructor called" << std::endl;
	this->_brainPTR = new Brain(*src._brainPTR);
	return;
}

Cat::~Cat(void)
{
	std::cout << "Cat's destructor called" << std::endl;
	delete _brainPTR;
	return;
}

Cat& Cat::operator=(Cat const& src)
{
	if (this != &src)
	{
		Animal::operator=(src);
		this->_brainPTR = new Brain(*src._brainPTR);
	}
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Miauuuuww" << std::endl;
}

Brain* Cat::getBrains(void) const
{
	return this->_brainPTR;
}

