/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:27:18 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/31 18:51:29 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H
# include <iostream>

class Harl
{
public:
	Harl( void );
	~Harl( void );
	void complain( std::string level );
	typedef void(Harl::*funcPtr)();
	funcPtr pointers[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
};

#endif