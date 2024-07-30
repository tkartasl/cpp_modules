/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:59:58 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/30 14:42:02 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
public:
	HumanB( std::string name );
	~HumanB( void );
	void	setWeapon( Weapon &weapon );
	void	attack( void ) const;
private:
	std::string _myname;
	Weapon*		_myweapon;
};

#endif
