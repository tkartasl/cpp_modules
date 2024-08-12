/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:49:32 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/09 12:26:47 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) //: _type("Dog")
{
	std::cout << "Dog's constructor called" << std::endl;
	this->_type = "Dog";
	return;
}

Dog::Dog(Dog const& src)
{
	std::cout << "Dog's copy constructor called" << std::endl;
	this->_type = src._type;
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
		this->_type = src._type;
	return *this;
}