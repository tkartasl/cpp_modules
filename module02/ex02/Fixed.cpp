/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:11:12 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/02 10:39:29 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : value(0)
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

Fixed::Fixed( int const i )
{
	std::cout << "Int constructor called" << std::endl;
	this->value = i << (this->fraction_bits);
	return;
}

Fixed::Fixed( float const f)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf((f * (1 << this->fraction_bits)));
	return;
}

Fixed &	Fixed::operator=( Fixed const & cl )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &cl)
		this->value = cl.getRawBits();
	return *this;
}

Fixed 	Fixed::operator+( Fixed const & cl ) const
{
	return Fixed(this->value + cl.getRawBits());
}

Fixed 	Fixed::operator-( Fixed const & cl ) const
{
	std::cout << "Subtraction operator called" << std::endl;
	return Fixed(this->value - cl.getRawBits());
}

Fixed 	Fixed::operator*( Fixed const & cl ) const
{
	std::cout << "Multiplycation operator called" << std::endl;
	return Fixed(this->value * cl.getRawBits());
}

Fixed 	Fixed::operator/( Fixed const & cl ) const
{
	std::cout << "Division operator called" << std::endl;
	return Fixed(this->value / cl.getRawBits());
}

bool 	Fixed::operator>( Fixed const & cl ) const
{
	std::cout << "Greater than operator called" << std::endl;
	return (this->value > cl.getRawBits());
}

bool 	Fixed::operator<( Fixed const & cl ) const
{
	std::cout << "Less than operator called" << std::endl;
	return (this->value < cl.getRawBits());
} 

bool 	Fixed::operator<=( Fixed const & cl ) const
{
std::cout << "Less or equal operator called" << std::endl;
return (this->value <= cl.getRawBits());
}

bool 	Fixed::operator>=( Fixed const & cl ) const
{
	std::cout << "Greater or equal operator called" << std::endl;
	return (this->value >= cl.getRawBits());
}

bool 	Fixed::operator==( Fixed const & cl ) const
{
	std::cout << "Equal operator called" << std::endl;
	return (this->value == cl.getRawBits());
}

bool 	Fixed::operator!=( Fixed const & cl ) const
{
	std::cout << "Not equal operator called" << std::endl;
	return (this->value != cl.getRawBits());
}

Fixed & Fixed::operator++( void )
{
	this->value++;
	return *this;
}

Fixed Fixed::operator++( int )
{
	Fixed temp(*this);

	operator++();
	return temp;
}

Fixed & Fixed::operator--( void )
{
	--this->value;
	return *this;
}

Fixed Fixed::operator--( int )
{
	Fixed temp(*this);

	operator--();
	return temp;
}

Fixed &	Fixed::min( Fixed & a, Fixed & b )
{
	if (a < b)
		return a;
	return b;
}

Fixed const &	Fixed::min( Fixed const & a, Fixed const & b )
{
	if (a < b)
		return a;
	return b;
}

Fixed &	Fixed::max( Fixed & a, Fixed & b )
{
	if (a > b)
		return a;
	return b;
}

Fixed const &	Fixed::max( Fixed const & a, Fixed const & b )
{
	if (a > b)
		return a;
	return b;
}


int	Fixed::getRawBits( void ) const
{
	return this->value;
}

void	Fixed::setRawBits( int const raw )
{
	this->value = raw;
}

float	Fixed::toFloat( void ) const
{
	return (float)this->value / (1 << this->fraction_bits);
}

int	Fixed::toInt( void ) const
{
	return (float)(this->value / 256);
}

std::ostream & operator<<(std::ostream & o, Fixed const & f)
{
	o << f.toFloat();
	return o;
}
