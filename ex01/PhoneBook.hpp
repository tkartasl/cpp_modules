/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:56:05 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/24 15:13:51 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# define MaxContacts 8
# include "Contact.hpp"

class PhoneBook
{
public:

	PhoneBook( void );
	~PhoneBook( void );

	void	GetContact( int index ) const;
	void	SetContact( Contact contact );

private:

	int	_count;
	Contact _contacts[MaxContacts];
};

#endif