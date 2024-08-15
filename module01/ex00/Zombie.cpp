/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:40:49 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/14 10:19:58 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( void )
{
	return;
}

Zombie::~Zombie( void )
{
	std::cout << "zombie: " << this->_name << " destroyed" << std::endl;
	return;
}

void	Zombie::setName( std::string name )
{
	this->_name = name;
}

void	Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}