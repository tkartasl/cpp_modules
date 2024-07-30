/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:59:19 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/30 14:35:34 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
public:
	HumanA( std::string name, Weapon &weapon );
	~HumanA( void );
	void	attack( void ) const;
private:
	std::string _myname;
	Weapon&		_myweapon;
};

#endif