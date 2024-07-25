/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:33:18 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/25 16:09:19 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <string.h>
#include <iostream>
#include <iomanip>
#include <stdio.h>

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
	u_int8_t	i; 
	const char	*inputs[5] = {"first name", "last name", "nickname", "phone number", "darkest secret"};

	i = 0;
	while(i < 5)
	{
		printf("%d\n", i);
		std::cout << "Enter " << inputs[i] << ": ";
		std::getline(std::cin, input);
		if (!input.empty())
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
		std::cout.clear();
		std::cin.clear();
	}
	book.SetContact(contact);
	return (book);
}

bool CheckIfDigit(std::string str)
{	
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (std::isdigit(str[i] == 0))
			return (false);
		i++;
	}
	return (true);
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

u_int8_t	GetIndex(PhoneBook book)
{
	std::string index;

	while (1)
	{	
		std::cout << "Give index(0-7) to search for a contact: ";
		std::getline(std::cin, index);
		if (CheckIfDigit(index) == false)
		{
			std::cout << "Incorrect index";
			std::cout.clear();
			std::cin.ignore();
		}
		else if (index >= book.GetCount())
		{
			std::cout << "No contact in given index";
			std::cout.clear();
			std::cin.ignore();
		}
		else
			break;
	}
	return (index);
}

void	SearchContact(PhoneBook book)
{
	u_int8_t	i;
	u_int8_t	index;

	index = 0;
	i = 0;
	SetFirstRow();
	while (i < book.GetCount())
	{
		std::cout << std::setw (ColumnSize) << i;
		std::cout << " | ";
		if (book.GetContact(i).GetFirstName().length() > ColumnSize)
			book.GetContact(i).GetFirstName().append(".", 9, 1);
		std::cout << std::setw (ColumnSize) << book.GetContact(i).GetFirstName();
		std::cout << " | ";
		if (book.GetContact(i).GetLastName().length() > ColumnSize)
			book.GetContact(i).GetLastName().append(".", 9, 1);
		std::cout << std::setw (ColumnSize) << book.GetContact(i).GetLastName();
		std::cout << " | ";
		if (book.GetContact(i).GetNickName().length() > ColumnSize)
			book.GetContact(i).GetNickName().append(".", 9, 1);
		std::cout << std::setw (ColumnSize) << book.GetContact(i).GetNickName();
		std::cout << " | ";
		if (book.GetContact(i).GetPhoneNumber().length() > ColumnSize)
			book.GetContact(i).GetPhoneNumber().append(".", 9, 1);
		std::cout << std::setw (ColumnSize) << book.GetContact(i).GetPhoneNumber();
		std::cout << " | ";
		if (book.GetContact(i).GetDarkestSecret().length() > ColumnSize)
			book.GetContact(i).GetDarkestSecret().append(".", 9, 1);
		std::cout << std::setw (ColumnSize) << book.GetContact(i).GetLastName() << std::endl;
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