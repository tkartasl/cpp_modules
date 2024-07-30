/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:58:49 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/30 13:56:17 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string newtype ) : _type(newtype)
{
	return;
}

Weapon::~Weapon()
{
	return;
}

std::string const & Weapon::getType( void ) const
{
	return (this->_type);
}

void	Weapon::setType( std::string newtype )
{
	this->_type = newtype;
}