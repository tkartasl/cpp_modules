/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:01:51 by tomppa            #+#    #+#             */
/*   Updated: 2024/08/06 15:22:59 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap pekka( ScavTrap("pekka"));
	ScavTrap jorma( ScavTrap("jorma"));
	ClapTrap tomi( ClapTrap("tomi"));
	
	pekka.attack("tomi");
	tomi.attack("pekka");
	std::cout << jorma.getEnergyPoints() << std::endl;
	jorma.attack("pekka");
	pekka.beRepaired(42);
	jorma.guardGate();
	return (0);
}