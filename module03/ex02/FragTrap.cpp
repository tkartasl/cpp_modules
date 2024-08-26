/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:43:23 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/26 14:44:07 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("")
{
	std::cout << "FragTrap's Constructor called" << std::endl;
	return;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_attackDamage = 30;
	this->_energyPoints = 100;
	std::cout << "FragTrap's " << name << " Constructor called" << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const& src) : ClapTrap(src)
{
	std::cout << "FragTrap's " << this->_name << " copy constructor called" << std::endl;
	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap's " << this->_name << " Destructor called" << std::endl;
	return;
}

FragTrap& FragTrap::operator=(FragTrap const& src)
{
	if (this != &src)
	{
		ClapTrap::operator=(src);
	}
	return *this;
}

void FragTrap::attack(const std::string& target)
{	
	if (this->_hitPoints <= 0)
		std::cout << "Out of Hitpoints" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "Not enough Energypoints to attack" << std::endl;
	else
		std::cout << "FragTrap " << this->_name <<  " attacks " << target << " causing " <<  this->_attackDamage << " Points of damage" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints <= 0)
		std::cout << "Out of Hitpoints" << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " smiles and asks everyone for epic high fives" << std::endl;
}