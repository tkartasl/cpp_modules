/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:55:58 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/25 09:30:03 by tkartasl         ###   ########.fr       */
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

void	PhoneBook::GetContact(int index) const
{
	if (index < 0 || index > 7)
		std::cout << "index has to be within 0-7 range" << std::endl;
	else
	{
		std::cout << this->_contacts[index].GetFirstName() << std::endl;
		std::cout << this->_contacts[index].GetLastName() << std::endl;
		std::cout << this->_contacts[index].GetNickName() << std::endl;
		std::cout << this->_contacts[index].GetPhoneNumber() << std::endl;
		std::cout << this->_contacts[index].GetDarkestSecret() << std::endl;
	}
}

void	PhoneBook::SetContact(Contact contact)
{
	if (this->_count >= 8)
		this->_count = 0;
	this->_contacts[this->_count] = contact;
	this->_count += 1;
}
