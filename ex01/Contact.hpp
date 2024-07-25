/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:56:15 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/25 09:16:37 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H
# include <iostream>

class Contact
{
public:

	Contact(void);
	~Contact(void);

	void		SetFirstName(std::string);
	void		SetLastName(std::string);
	void		SetNickName(std::string);
	void		SetPhoneNumber(std::string);
	void		SetDarkestSecret(std::string);
	std::string	GetFirstName(void) const;
	std::string	GetLastName(void) const;
	std::string GetNickName(void) const;
	std::string GetPhoneNumber(void) const;
	std::string GetDarkestSecret(void) const;

private:

	std::string _FirstName;
	std::string _LastName;
	std::string _NickName;
	std::string _PhoneNumber;
	std::string _DarkestSecret;
};

#endif