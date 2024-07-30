/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:59:29 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/30 14:33:52 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon ) : _myname(name), _myweapon(weapon)
{
	return;
}

HumanA::~HumanA( void )
{
	return;
}

void	HumanA::attack( void ) const
{
	std::cout << this->_myname << " attacks with their " << this->_myweapon.getType() << std::endl;
}
