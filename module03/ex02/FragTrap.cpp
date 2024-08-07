/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:43:23 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/06 15:57:54 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name)
{
	std::cout << "FragTrap's Constructor called" << std::endl;
	setName(name);
	setHitPoints(100);
	setAttackDamage(30);
	setEnergyPoints(100);
	return;
}

FragTrap::FragTrap(FragTrap const & src)
{
	setName(src.getName());
	setHitPoints(src.getEnergyPoints());
	setAttackDamage(src.getAttackDamage());
	setEnergyPoints(src.getEnergyPoints());
	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap's Destructor called" << std::endl;
	return;
}

FragTrap & FragTrap::operator=(FragTrap const & src)
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

void FragTrap::attack(const std::string& target)
{	
	if (getHitPoints() <= 0)
		std::cout << "Out of Hitpoints" << std::endl;
	else if (getEnergyPoints() == 0)
		std::cout << "Not enough Energypoints to attack" << std::endl;
	else
		std::cout << "FragTrap " << getName() <<  " attacks " << target << " causing " <<  getAttackDamage() << " Points of damage" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << getName() << " smiles and asks everyone for epic high fives" << std::endl;
}