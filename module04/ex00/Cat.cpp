/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:45:21 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/09 12:26:59 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) //: _type("Cat")
{
	std::cout << "Cat's constructor called" << std::endl;
	this->_type = "Cat";
	return;
}

Cat::Cat(Cat const& src)
{
	std::cout << "Cat's constructor called" << std::endl;
	this->_type = src._type;
	return;
}

Cat::~Cat(void)
{
	std::cout << "Cat's destructor called" << std::endl;
	return;
}

Cat& Cat::operator=(Cat const& src)
{
	if (this != &src)
		this->_type = src._type;
	return *this;
}