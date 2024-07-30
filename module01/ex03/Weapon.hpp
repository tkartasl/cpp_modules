/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:58:38 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/30 13:23:05 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H
# include <iostream>

class Weapon
{
public:
	Weapon( std::string newtype );
	~Weapon( void );
	std::string const & getType( void ) const;
	void	setType( std::string newtype );
private:
	std::string	_type;
};

#endif

