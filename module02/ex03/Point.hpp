/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:43:35 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/02 15:32:26 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H
# include <iostream>
# include "Fixed.hpp"

class Point
{
public:
	Point( void );
	Point ( Point const & src );
	Point( float const a, float const b );
	~Point( void );

	Point & operator=( Point const & src );
	Fixed getX( void ) const;
	Fixed getY( void ) const;

private:
	Fixed const x;
	Fixed const y;
};

#endif