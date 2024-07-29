/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:55:58 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/29 11:10:38 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"
#include <limits>
#include <string>

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
	static int	index;

	if (index >= 8)
		index = 0;
	this->_contacts[index] = contact;
	if (this->_count < 8)
		this->_count++;
	index++;
}

int PhoneBook::VerifyIndex(std::string str) const
{
	int	i;

	i = 0;
	for (char ch : str)
	{
		if (!isdigit(ch))
		{
			std::cout << "Index has to be an number in the range of 0-7" << std::endl;
			return (-1);
		}
	}
	if (str.length() >= 2 || str.length() == 0)
	{
		std::cout << "Index has to be an number in the range of 0-7" << std::endl;
		return (-1);
	}
	i = std::stoi(str, nullptr, 10);
	if (i >= 0 && i < 8)
		return (i);
	else
	{
		std::cout << "Index has to be an number in the range of 0-7" << std::endl;
		return (-1);
	}
}

int	PhoneBook::GetIndex(void) const
{
	std::string index;
	int			i;

	i = 0;
	while (1)
	{
		std::cout << "Give index(0-7) to search for a contact: ";
		std::getline(std::cin, index);
		i = VerifyIndex(index);
		if (i < 0)
			continue;
		else if (this->GetCount() == 0)
		{
			std::cout << "No contacts in the phone book" << std::endl;
			return (-1);
		}
		else if (i >= this->GetCount())
			std::cout << "No contact in given index" << std::endl;
		else
			break;
	}
	return (i);
}

void	PhoneBook::SetFirstRow(void) const
{
	std::cout << std::setw (ColumnSize) << "index";
	std::cout << " | ";
	std::cout << std::setw (ColumnSize) << "first name";
	std::cout << " | ";
	std::cout << std::setw (ColumnSize) << "last name";
	std::cout << " | ";
	std::cout << std::setw (ColumnSize) << "nickname" << std::endl;
}

void	PhoneBook::PrintTruncated(std::string str) const
{
	std::string truncated_str;
	
	truncated_str = str.substr(0, 9);
	truncated_str.append(".");
	std::cout << std::setw (ColumnSize) << truncated_str;
}

void	PhoneBook::PrintContact(u_int8_t index)  const
{
	std::cout << "First name: " << this->GetContact(index).GetFirstName() << std::endl;
	std::cout << "Last name: " << this->GetContact(index).GetLastName() << std::endl;
	std::cout << "Nickname: " << this->GetContact(index).GetNickName() << std::endl;
	std::cout << "Phone number: " << this->GetContact(index).GetPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->GetContact(index).GetDarkestSecret() << std::endl;
}

void	PhoneBook::SearchContact(void) const
{
	int			i;
	int			index;

	index = 0;
	i = 0;
	SetFirstRow();
	while (i < this->GetCount())
	{
		std::cout << std::setw (ColumnSize) << i;
		std::cout << " | ";
		if (this->GetContact(i).GetFirstName().length() >= ColumnSize)
			PrintTruncated(this->GetContact(i).GetFirstName());
		else
			std::cout << std::setw (ColumnSize) << this->GetContact(i).GetFirstName();
		std::cout << " | ";
		if (this->GetContact(i).GetLastName().length() >= ColumnSize)
			PrintTruncated(this->GetContact(i).GetLastName());
		else
			std::cout << std::setw (ColumnSize) << this->GetContact(i).GetLastName();
		std::cout << " | ";
		if (this->GetContact(i).GetNickName().length() >= ColumnSize)
		{
			PrintTruncated(this->GetContact(i).GetNickName());
			std::cout << std::endl;
		}
		else
			std::cout << std::setw (ColumnSize) << this->GetContact(i).GetNickName() << std::endl;
		i++;
	}
	index = this->GetIndex();
	if (index < 0)
		return;
	this->PrintContact(index);
}

void	PhoneBook::AddContact(void)
{
	Contact		contact;
	std::string	input;
	int			i; 
	const char	*inputs[5] = {"first name", "last name", "nickname", "phone number", "darkest secret"};

	i = 0;
	while(i < 5)
	{
		std::cout << "Enter " << inputs[i] << ": ";
		std::getline(std::cin, input);
		if (input.empty() == false)
		{
			if (i == 0)
				contact.SetFirstName(input);
			else if (i == 1)
				contact.SetLastName(input);
			else if (i == 2)
				contact.SetNickName(input);
			else if (i == 3)
				contact.SetPhoneNumber(input);
			else
				contact.SetDarkestSecret(input);
			i += 1;
		}
	}
	this->SetContact(contact);
}