/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:10:59 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/16 10:48:12 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
# include <iostream>

class	Fixed
{
public:
	Fixed(void);
	Fixed(Fixed const & src);
	~Fixed(void);

	Fixed &	operator=(Fixed const & cl);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
private:
	int					_value;
	static const	int _fraction_bits = 8;
};

#endif