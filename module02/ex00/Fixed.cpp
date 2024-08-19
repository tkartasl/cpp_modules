/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:11:12 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/16 10:49:56 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(src);
	return;
}

Fixed &	Fixed::operator=( Fixed const & cl )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &cl)
		this->_value = cl.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void	Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}
