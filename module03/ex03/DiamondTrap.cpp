/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:18:38 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/29 15:55:05 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap's constructor called" << std::endl;
	this->_name = "";
	ClapTrap::_name ="_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	this->_energyPoints = ScavTrap::_energyPoints;
	return;	
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap's " << name << " constructor called" << std::endl;
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	this->_energyPoints = ScavTrap::_energyPoints;
	return;	
}

DiamondTrap::DiamondTrap(DiamondTrap const& src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	std::cout << "DiamondTrap's copy constructor called" << std::endl;
	this->ClapTrap::_name = src.ClapTrap::_name;

	return;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& src)
{
	if (this != &src)
	{
		ClapTrap::operator=(src);
		ClapTrap::_name = src.ClapTrap::_name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap's " << this->_name << " Destructor called" << std::endl;
	return;	
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTraps name is: " << this->_name << std::endl;
	std::cout << "DiamondTraps clap name is: " << ClapTrap::_name << std::endl;
}
