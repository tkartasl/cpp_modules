/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:56:05 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/25 09:08:04 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# define MaxContacts 8
# include "Contact.hpp"

class PhoneBook
{
public:

	PhoneBook(void);
	~PhoneBook(void);

	void		SetContact(Contact contact);
	void		SetCount(u_int8_t _count);
	void		GetContact(int index) const;
	u_int8_t	GetCount(void) const;	

private:

	u_int8_t	_count;
	Contact		_contacts[MaxContacts];
};

#endif