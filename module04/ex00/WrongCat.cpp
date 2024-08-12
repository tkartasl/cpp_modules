/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:16:46 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/09 12:26:14 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat's constructor called" << std::endl;
	this->_type = "WrongCat";
	return;
}

WrongCat::WrongCat(WrongCat const& src)
{
	std::cout << "WrongCat's copy constructor called" << std::endl;
	this->_type = src._type;
	return;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat's destructor called" << std::endl;
	return;
}

WrongCat& WrongCat::operator=(WrongCat const& src)
{
	if (this != &src)
		this->_type = src._type;
	return *this;
}