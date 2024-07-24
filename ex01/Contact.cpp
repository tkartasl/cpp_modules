/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:56:09 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/24 15:11:47 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact( void )
{
	return;	
}

Contact::~Contact( void )
{
	return;
}

void Contact::SetFirstName( std::string input)
{
	if (input.empty())
	{
		std::cout << "No firstname given" << std::endl;
		return;
	}
	this->_FirstName = input;
}

void Contact::SetLastName( std::string input)
{
	if (input.empty())
	{
		std::cout << "No lastname given" << std::endl;
		return;
	}
	this->_LastName = input;
}

void Contact::SetNickName( std::string input)
{
	if (input.empty())
	{
		std::cout << "No nickname given" << std::endl;
		return;
	}
	this->_NickName = input;
}

void Contact::SetPhoneNumber( std::string input)
{
	if (input.empty())
	{
		std::cout << "No phonenumber given" << std::endl;
		return;
	}
	this->_PhoneNumber = input;
}

void Contact::SetDarkestSecret( std::string input)
{
	if (input.empty())
	{
		std::cout << "No darkest secret given" << std::endl;
		return;
	}
	this->_DarkestSecret = input;
}

std::string Contact::GetFirstName( std::string ) const
{
	return this->_FirstName;
}

std::string Contact::GetLastName( std::string ) const
{
	return this->_LastName;
}

std::string Contact::GetNickName( std::string ) const
{
	return this->_NickName;
}

std::string Contact::GetPhoneNumber( std::string ) const
{
	return this->_PhoneNumber;
}

std::string Contact::GetDarkestSecret( std::string ) const
{
	return this->_DarkestSecret;
}