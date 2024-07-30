/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:40:11 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/30 09:09:38 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int	main( void )
{
	Zombie		*z;

	z = newZombie("Mikko");
	if (!z)
		return (1);
	z->announce(); 
	randomChump("Teppo");
	delete z;
	return (0);
}