/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:56:05 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/25 15:10:03 by tkartasl         ###   ########.fr       */
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

	void		SetContact(Contact contact);
	u_int8_t	GetCount(void) const;
	Contact		GetContact(u_int8_t index) const;

private:

	u_int8_t	_count;
	Contact		_contacts[MaxContacts];
};

#endif