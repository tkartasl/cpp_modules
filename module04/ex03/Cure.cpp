/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:18:10 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/27 10:26:20 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure")
{
	this->_type = "cure";
	return;	
}

Cure::Cure(const Cure& src) : AMateria(src)
{
	return;
}

Cure::~Cure(void)
{
	return;
}
Cure& Cure::operator=(const Cure& src)
{
	if (this != &src)
	{
		AMateria::operator=(src);
		*this = src;
	}
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