/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:01:51 by tomppa            #+#    #+#             */
/*   Updated: 2024/08/29 15:54:50 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	ClapTrap keijo("keijo");
	DiamondTrap jussi("jussi");
	ScavTrap jorma("jorma");
	FragTrap tomi("tomi");
	FragTrap l;
	
	l = tomi;
	l.highFivesGuys();
	jussi.attack("tomi");
	tomi.attack("jussi");
	jorma.attack("himself");
	jussi.whoAmI();
	jussi.highFivesGuys();
	jussi.guardGate();
	jussi.beRepaired(42);
	return (0);
}