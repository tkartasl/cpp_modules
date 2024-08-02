/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:10:59 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/01 14:09:19 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
# include <iostream>
# include <cmath>
class	Fixed
{
public:
	Fixed( void );
	Fixed( Fixed const & src );
	Fixed( int const i );
	Fixed( float const f);
	~Fixed( void );

	Fixed &	operator=( Fixed const & cl );
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int 	toInt( void ) const;
private:
	int					value;
	static const	int fraction_bits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & f);

#endif