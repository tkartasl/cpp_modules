/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:56:05 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/26 14:00:25 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# define MaxContacts 8
# define ColumnSize 10
# define MaxInputLen 100
# include "Contact.hpp"

class PhoneBook
{
public:

	PhoneBook(void);
	~PhoneBook(void);

	u_int8_t	GetCount(void) const;
	void		SearchContact(void) const;
	void		AddContact(void);

private:

	u_int8_t	_count;
	Contact		_contacts[MaxContacts];
	Contact		GetContact(u_int8_t index) const;
	int			GetIndex(void) const;
	void		SetFirstRow(void) const;
	void		PrintTruncated(std::string str) const;
	int 		VerifyIndex(std::string str) const;
	void		PrintContact(u_int8_t index)  const;
	void		SetContact(Contact contact);
};

#endif