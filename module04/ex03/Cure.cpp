/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:18:10 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/13 13:18:26 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria()
{
	this->_type = "ice";
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
	return *this;
}