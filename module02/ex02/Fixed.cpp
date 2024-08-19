/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:11:12 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/19 12:13:38 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	return;
}

Fixed::~Fixed(void)
{
	return;
}

Fixed::Fixed(Fixed const & src) : _value(src._value)
{
	return;
}

Fixed::Fixed(int const i)
{
	this->_value = i << (this->_fraction_bits);
	return;
}

Fixed::Fixed(float const f)
{
	this->_value = roundf((f * (1 << this->_fraction_bits)));
	return;
}

Fixed &	Fixed::operator=(Fixed const & cl)
{
	if (this != &cl)
		this->_value = cl.getRawBits();
	return *this;
}

Fixed 	Fixed::operator+(Fixed const & cl) const
{
	return Fixed(this->toFloat() + cl.toFloat());
}

Fixed 	Fixed::operator-(Fixed const & cl) const
{
	return Fixed(this->toFloat() - cl.toFloat());
}

Fixed 	Fixed::operator*(Fixed const & cl) const
{
	return Fixed(this->toFloat() * cl.toFloat());
}

Fixed 	Fixed::operator/(Fixed const & cl) const
{
	return Fixed(this->toFloat() / cl.toFloat());
}

bool 	Fixed::operator>(Fixed const & cl) const
{
	return (this->_value > cl.getRawBits());
}

bool 	Fixed::operator<(Fixed const & cl) const
{
	return (this->_value < cl.getRawBits());
} 

bool 	Fixed::operator<=(Fixed const & cl) const
{
	return (this->_value <= cl.getRawBits());
}

bool 	Fixed::operator>=(Fixed const & cl) const
{
	return (this->_value >= cl.getRawBits());
}

bool 	Fixed::operator==(Fixed const & cl) const
{
	return (this->_value == cl.getRawBits());
}

bool 	Fixed::operator!=(Fixed const & cl) const
{
	return (this->_value != cl.getRawBits());
}

Fixed & Fixed::operator++(void)
{
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);

	operator++();
	return temp;
}

Fixed & Fixed::operator--(void)
{
	--this->_value;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);

	operator--();
	return temp;
}

Fixed &	Fixed::min(Fixed & a, Fixed & b)
{
	if (a < b)
		return a;
	return b;
}

Fixed const &	Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a < b)
		return a;
	return b;
}

Fixed &	Fixed::max(Fixed & a, Fixed & b)
{
	if (a > b)
		return a;
	return b;
}

Fixed const &	Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a > b)
		return a;
	return b;
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
	return (float)this->_value / (1 << this->_fraction_bits);
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
