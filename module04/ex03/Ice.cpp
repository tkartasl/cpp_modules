/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:10:27 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/13 13:17:43 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

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
	return *this;
}