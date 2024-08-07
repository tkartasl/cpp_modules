/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:01:51 by tomppa            #+#    #+#             */
/*   Updated: 2024/08/07 12:32:45 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap pekka("pekka");
	ScavTrap jorma("jorma");
	ClapTrap tomi("tomi");
	
	pekka.attack("tomi");
	tomi.attack("pekka");
	jorma.attack("pekka");
	pekka.beRepaired(42);
	jorma.guardGate();
	return (0);
}