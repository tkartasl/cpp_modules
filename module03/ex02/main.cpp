/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:01:51 by tomppa            #+#    #+#             */
/*   Updated: 2024/08/07 13:18:43 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap pekka("pekka");
	ScavTrap jorma("jorma");
	FragTrap tomi("tomi");
	
	pekka.attack("tomi");
	tomi.attack("pekka");
	jorma.attack("pekka");
	pekka.takeDamage(20);
	pekka.beRepaired(42);
	tomi.highFivesGuys();
	return (0);
}