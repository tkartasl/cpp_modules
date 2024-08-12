/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:44:24 by tomppa            #+#    #+#             */
/*   Updated: 2024/08/08 13:16:29 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_name = ("");
	this->_hitPoints = 100;
	this->_attackDamage = 20;
	this->_energyPoints = 50;
	std::cout << "ScavTrap's Constructor called" << std::endl;
	return;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap's " << name << " Constructor called" << std::endl;
	this->_name = (name);
	this->_hitPoints = 100;
	this->_attackDamage = 20;
	this->_energyPoints = 50;
	return;
}

ScavTrap::ScavTrap(ScavTrap const& src)
{
	std::cout << "ScavTrap's copy constructor called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_attackDamage = src._attackDamage;
	this->_energyPoints = src._energyPoints;
	return;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap's " << this->_name << " Destructor called" << std::endl;
	return;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_attackDamage = src._attackDamage;
		this->_energyPoints = src._energyPoints;
	}
	return *this;
}

void ScavTrap::attack(const std::string& target)
{	
	if (this->_hitPoints <= 0)
		std::cout << "Out of Hitpoints" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "Not enough Energypoints to attack" << std::endl;
	else
		std::cout << "ScavTrap " << this->_name <<  " attacks " << target << " causing " <<  this->_attackDamage << " Points of damage" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gatekeeper mode" << std::endl;
}