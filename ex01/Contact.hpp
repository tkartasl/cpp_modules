/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:56:15 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/24 15:11:40 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H
# include <iostream>

class Contact
{
public:

	Contact( void );
	~Contact( void );

	void		SetFirstName( std::string );
	void		SetLastName( std::string );
	void		SetNickName( std::string );
	void		SetPhoneNumber( std::string );
	void		SetDarkestSecret( std::string );
	std::string	GetFirstName( std::string ) const;
	std::string	GetLastName( std::string ) const;
	std::string GetNickName( std::string ) const;
	std::string GetPhoneNumber( std::string ) const;
	std::string GetDarkestSecret( std::string ) const;

private:

	std::string _FirstName;
	std::string _LastName;
	std::string _NickName;
	std::string _PhoneNumber;
	std::string _DarkestSecret;
};

#endif