/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:49:32 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/12 16:02:58 by tkartasl         ###   ########.fr       */
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

Dog::Dog(Dog const& src)
{
	std::cout << "Dog's copy constructor called" << std::endl;
	this->_type = src._type;
	this->_brainPTR = src._brainPTR;
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
		this->_type = src._type;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Wuf wuf" << std::endl;
}

std::string* Dog::getDogIdeas(void)
{
	return this->_brainPTR->getIdeas();
}

void Dog::setDogIdeas(std::string dog_idea)
{
	this->_brainPTR->setIdeas(dog_idea);
}