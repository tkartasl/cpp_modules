/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:56:05 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/07 14:43:31 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# define MaxContacts 8
# define ColumnSize 10
# include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook(void);
	~PhoneBook(void);

	void		searchContact(void) const;
	void		addContact(void);

private:
	u_int8_t	_count;
	Contact		_contacts[MaxContacts];
	Contact		_getContact(u_int8_t index) const;
	int			_getIndex(void) const;
	void		_setFirstRow(void) const;
	void		_printTruncated(std::string str) const;
	int 		_verifyIndex(std::string str) const;
	void		_printContact(u_int8_t index)  const;
	void		_setContact(Contact contact);
	u_int8_t	_getCount(void) const;
};

#endif