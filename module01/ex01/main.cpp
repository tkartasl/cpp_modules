/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:40:11 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/30 09:08:04 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main( void )
{
	Zombie		*horde;
	horde = zombieHorde(5, "Olavi");
	if (!horde)
		return (1);
	for (int i = 0; i < 5; i++)
	{
		horde[i].announce();
	}
	delete [] horde;
	return (0);
}