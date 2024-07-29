/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:27:53 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/29 17:46:37 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*zombieArray;

	zombieArray = new Zombie[N];
	
	for (int i = 0; i < N; i++)
	{
		zombieArray[i].setName(name);
	}
return (zombieArray);
}