/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:44:24 by tomppa            #+#    #+#             */
/*   Updated: 2024/08/06 15:13:24 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name)
{
	std::cout << "ScavTrap's Constructor called" << std::endl;
	setName(name);
	setHitPoints(100);
	setAttackDamage(20);
	setEnergyPoints(50);
	return;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	setName(src.getName());
	setHitPoints(src.getEnergyPoints());
	setAttackDamage(src.getAttackDamage());
	setEnergyPoints(src.getEnergyPoints());
	return;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap's Destructor called" << std::endl;
	return;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & src)
{
	if (this != &src)
	{
		setName(src.getName());
		setHitPoints(src.getEnergyPoints());
		setAttackDamage(src.getAttackDamage());
		setEnergyPoints(src.getEnergyPoints());
	}
	return *this;
}

void ScavTrap::attack(const std::string& target)
{	
	if (getHitPoints() <= 0)
		std::cout << "Out of Hitpoints" << std::endl;
	else if (getEnergyPoints() == 0)
		std::cout << "Not enough Energypoints to attack" << std::endl;
	else
		std::cout << "ScavTrap " << getName() <<  " attacks " << target << " causing " <<  getAttackDamage() << " Points of damage" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gatekeeper mode" << std::endl;
}