/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:27:53 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/30 09:07:34 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*zombieArray;

	zombieArray = new (std::nothrow) Zombie[N];
	if (!zombieArray)
		return (nullptr);
	for (int i = 0; i < N; i++)
	{
		zombieArray[i].setName(name);
	}
return (zombieArray);
}