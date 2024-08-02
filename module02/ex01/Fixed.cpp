/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:11:12 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/02 10:34:26 by tkartasl         ###   ########.fr       */
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
