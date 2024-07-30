/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:41:28 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/30 09:09:02 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie *zombie;

	zombie = nullptr;
	zombie = new (std::nothrow) Zombie;
	if (!zombie)
		return (nullptr);
	zombie->setName(name);
	return (zombie);
}