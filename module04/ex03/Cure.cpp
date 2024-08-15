/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:18:10 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/14 16:39:41 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria()
{
	this->_type = "cure";
	return;	
}

Cure::Cure(const Cure& src)
{
	this->_type  = src._type;
	return;
}

Cure::~Cure(void)
{
	return;
}
Cure& Cure::operator=(const Cure& src)
{
	(void)src;
	return *this;
}

void	Cure::use (ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria*	Cure::clone(void) const
{
	AMateria* newMateria = new Cure();
	return newMateria;
}