/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:22:57 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/08 13:17:23 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name(""), _hitPoints(10), _attackDamage(0), _energyPoints(10)
{
	std::cout << "ClapTrap's Constructor called" << std::endl;
	return;	
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _attackDamage(0), _energyPoints(10)
{
	std::cout << "ClapTrap's " << name << " Constructor called" << std::endl;
	return;	
}

ClapTrap::ClapTrap(ClapTrap const &src) : _name(src._name), _hitPoints(src._hitPoints), _attackDamage(src._attackDamage), _energyPoints(src._energyPoints)
{
	std::cout << "ClapTrap's copy constructor called" << std::endl;
	return;	
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
	return;	
}

ClapTrap & ClapTrap::operator=(ClapTrap const &src)
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

void ClapTrap::attack(const std::string& target)
{	
	if (this->_hitPoints <= 0)
		std::cout << "Out of Hitpoints" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "Not enough Energypoints to attack" << std::endl;
	else
		std::cout << "ClapTrap " << this->_name <<  " attacks " << target << " causing " <<  this->_attackDamage << " Points of damage" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->_name << " takes " << amount << " points of damage" << std::endl;
	this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
		std::cout << "Out of Hitpoints" << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << "Not enough Energypoints for repair" << std::endl;
	else
	{	
		this->_energyPoints -= 1;
		this->_hitPoints += amount;
		std::cout << this->_name << " is repairing himself" << std::endl; 	
	}
}