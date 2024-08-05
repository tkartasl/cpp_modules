/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:43:49 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/05 10:13:31 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : x(0), y(0)
{
	return;	
}

Point::Point ( Point const & src ) : x(src.x), y(src.y)
{
	return;
}

Point::Point( float const a, float const b ) : x(Fixed(a)), y(Fixed(b))
{
	return;	
}

Point::~Point( void )
{
	return;
}

Fixed Point::getX( void ) const
{
	return this->x;
}

Fixed Point::getY( void ) const
{
	return this->y;
}

Point & Point::operator=( Point const & src )
{
	(void)src;
	return *this;
}