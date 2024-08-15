/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:10:27 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/14 16:41:02 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice(void) : AMateria()
{
	this->_type = "ice";
	return;	
}

Ice::Ice(const Ice& src)
{
	this->_type  = src._type;
	return;
}

Ice::~Ice(void)
{
	return;
}
Ice& Ice::operator=(const Ice& src)
{
	(void)src;
	return *this;
}

void	Ice::use (ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria*	Ice::clone(void) const
{
	AMateria* newMateria = new Ice();
	return newMateria;
}