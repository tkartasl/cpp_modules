/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:11:12 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/16 11:32:47 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(src);
	return;
}

Fixed::Fixed(int const i)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = i << (this->_fraction_bits);
	return;
}

Fixed::Fixed(float const f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf((f * 256));
	return;
}

Fixed &	Fixed::operator=(Fixed const & cl)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &cl)
		this->_value = cl.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	return this->_value;
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
return (float)this->_value / 256;
}

int	Fixed::toInt(void) const
{
	return (float)(this->_value / 256);
}

std::ostream & operator<<(std::ostream & o, Fixed const & f)
{
	o << f.toFloat();
	return o;
}
