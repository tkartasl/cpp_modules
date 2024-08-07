/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:01:51 by tomppa            #+#    #+#             */
/*   Updated: 2024/08/06 16:00:13 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap pekka( ScavTrap("pekka"));
	ScavTrap jorma( ScavTrap("jorma"));
	FragTrap timo( FragTrap("timo"));
	ClapTrap tomi( ClapTrap("tomi"));

	timo.attack("pekka");
	timo.highFivesGuys();
	pekka.attack("timo");
	tomi.attack("pekka");
	jorma.attack("pekka");
	pekka.beRepaired(42);
	jorma.guardGate();
	return (0);
}