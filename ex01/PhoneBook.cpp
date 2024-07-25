/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:55:58 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/25 14:30:29 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_count = 0;
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

u_int8_t	PhoneBook::GetCount(void) const
{
	return this->_count;
}

Contact	PhoneBook::GetContact(u_int8_t index) const
{
	return this->_contacts[index];	
}

void	PhoneBook::SetContact(Contact contact)
{
	if (this->_count >= 8)
		this->_count = 0;
	this->_contacts[this->_count] = contact;
	this->_count += 1;
}