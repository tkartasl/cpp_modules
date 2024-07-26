/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomppa <tomppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:33:18 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/26 09:35:14 by tomppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>

void	PrintContact(u_int8_t index, PhoneBook book)
{
	std::cout << "First name: " << book.GetContact(index).GetFirstName() << std::endl;
	std::cout << "Last name: " << book.GetContact(index).GetLastName() << std::endl;
	std::cout << "Nickname: " << book.GetContact(index).GetNickName() << std::endl;
	std::cout << "Phone number: " << book.GetContact(index).GetPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << book.GetContact(index).GetDarkestSecret() << std::endl;
}

PhoneBook	AddContact(PhoneBook book)
{
	Contact		contact;
	std::string	input;
	int			i; 
	const char	*inputs[5] = {"first name", "last name", "nickname", "phone number", "darkest secret"};

	i = 0;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
	book.SetContact(contact);
	return (book);
}

int VerifyIndex(std::string str)
{	
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (std::isdigit(str[i] == 0))
		{
			std::cout << "Index has to be an number in the range of 0-7" << std::endl;
			return (-1);
		}
		i++;
	}
	if (i >= 2)
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

void	SetFirstRow(void)
{
	std::cout << std::setw (ColumnSize) << "index";
	std::cout << " | ";
	std::cout << std::setw (ColumnSize) << "first name";
	std::cout << " | ";
	std::cout << std::setw (ColumnSize) << "last name";
	std::cout << " | ";
	std::cout << std::setw (ColumnSize) << "nickname" << std::endl;
}

int	GetIndex(PhoneBook book)
{
	std::string index;
	int			i;

	i = 0;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (1)
	{
		std::cout << "Give index(0-7) to search for a contact: ";
		std::getline(std::cin, index);
		i = VerifyIndex(index);
		if (i < 0)
			continue;
		else if (i >= book.GetCount())
			std::cout << "No contact in given index" << std::endl;
		else
			break;
	}
	return (i);
}

void	PrintTruncated(std::string str)
{
	std::string truncated_str;
	
	truncated_str = str.substr(0, 9);
	truncated_str.append(".");
	std::cout << std::setw (ColumnSize) << truncated_str;
}

void	SearchContact(PhoneBook book)
{
	int			i;
	int			index;
	
	index = 0;
	i = 0;
	SetFirstRow();
	while (i < book.GetCount())
	{
		std::cout << std::setw (ColumnSize) << i;
		std::cout << " | ";
		if (book.GetContact(i).GetFirstName().length() >= ColumnSize)
			PrintTruncated(book.GetContact(i).GetFirstName());
		else
			std::cout << std::setw (ColumnSize) << book.GetContact(i).GetFirstName();
		std::cout << " | ";
		if (book.GetContact(i).GetLastName().length() >= ColumnSize)
			PrintTruncated(book.GetContact(i).GetLastName());
		else
			std::cout << std::setw (ColumnSize) << book.GetContact(i).GetLastName();
		std::cout << " | ";
		if (book.GetContact(i).GetNickName().length() >= ColumnSize)
		{
			PrintTruncated(book.GetContact(i).GetNickName());
			std::cout << std::endl;
		}
		else
			std::cout << std::setw (ColumnSize) << book.GetContact(i).GetNickName() << std::endl;
		i++;
	}
	index = GetIndex(book);
	PrintContact(index, book);
}

int	main(void)
{
	Contact		contact;
	PhoneBook	phonebook;
	std::string	command;

	while (1)
	{
		std::cout << "Enter a command (ADD/SEARCH/EXIT): ";		
		std::cin >> command;
		if (command == "ADD")
			phonebook = AddContact(phonebook);
		else if (command == "SEARCH")
			SearchContact(phonebook);
		else if (command == "EXIT")
			break;
		else
		{
			std::cout.clear();
			std::cin.ignore();
		}
	}
	return (0);
}