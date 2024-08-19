/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:10:59 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/16 10:56:27 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
# include <iostream>
# include <cmath>

class	Fixed
{
public:
	Fixed(void);
	Fixed(Fixed const & src);
	Fixed(int const i);
	Fixed(float const f);
	~Fixed(void);

	Fixed &	operator=(Fixed const & cl);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int 	toInt(void) const;
private:
	int	_value;
	static const int	_fraction_bits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & f);

#endif