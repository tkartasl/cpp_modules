/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:51:59 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/14 16:31:00 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const& type) : _type(type)
{
	return;
}
AMateria::AMateria(void)
{
	return;
}
AMateria::AMateria(const AMateria& src)
{
	this->_type = src._type;
	return;
}
AMateria::~AMateria(void)
{
	return;
}
AMateria& AMateria::operator=(const AMateria& src)
{
	(void)src;
	return *this;
}
std::string const& AMateria::getType(void) const
{
	return this->_type;
}

void	AMateria::use (ICharacter& target)
{
	(void)target;
	return;
}