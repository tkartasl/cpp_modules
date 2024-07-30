/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:00:06 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/30 14:42:25 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _myname(name), _myweapon(nullptr)
{
	return;
}

HumanB::~HumanB( void )
{
	return;
}

void	HumanB::setWeapon( Weapon &weapon )
{
	this->_myweapon = &weapon;
}

void	HumanB::attack( void ) const
{
	std::cout << this->_myname << " attacks with their " << this->_myweapon->getType() << std::endl;
}