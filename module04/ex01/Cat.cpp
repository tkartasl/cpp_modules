/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:45:21 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/12 16:03:23 by tkartasl         ###   ########.fr       */
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

Cat::Cat(Cat const& src)
{
	std::cout << "Cat's constructor called" << std::endl;
	this->_type = src._type;
	this->_brainPTR = src._brainPTR;
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
		this->_type = src._type;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Miauuuuww" << std::endl;
}

std::string* Cat::getCatIdeas(void)
{
	return this->_brainPTR->getIdeas();
}

void Cat::setCatIdeas(std::string cat_idea)
{
	this->_brainPTR->setIdeas(cat_idea);
}
