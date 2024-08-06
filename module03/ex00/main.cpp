/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:01:51 by tomppa            #+#    #+#             */
/*   Updated: 2024/08/06 13:58:20 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap tomi(ClapTrap("tomi"));
	ClapTrap botti(ClapTrap("botti"));
	ClapTrap heppu(ClapTrap("botti"));
	ClapTrap pertti(tomi);
	
	heppu = tomi;
	tomi.attack("botti");
	botti.takeDamage(10);
	botti.beRepaired(5);
	heppu.attack("jeppe");
	pertti.attack("jaska");
	pertti.beRepaired(420);
	return (0);
}