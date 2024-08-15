/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:30:10 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/14 17:46:55 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(void)	: ICharacter(), _name("")
{
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = 0;
	}
	for (int i = 0; i < 42; i++)
	{
		this->_trashBin[i] = 0;
	}
	return;
}
	
Character::Character(std::string const name) : ICharacter(), _name(name)
{
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = {0};
	}
	for (int i = 0; i < 42; i++)
	{
		this->_trashBin[i] = 0;
	}
	return;
}
	
Character::Character(const Character& src)
{
	this->_name = src._name;
	for (int i = 0; i < 4; i++)
	{
		delete this->_inventory[i];
		this->_inventory[i] = src._inventory[i]->clone();
		this->_trashBin[i] = src._trashBin[i];
	}
	for (int i = 0; i < 42; i++)
	{
		delete this->_trashBin[i];
		this->_trashBin[i] = src._inventory[i]->clone();
	}
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		delete this->_inventory[i];
	}
	for (int i = 0; i < 42; i++)
	{
		delete this->_trashBin[i];
	}
	return;
}
	
Character& Character::operator=(const Character& src)
{
	if (this != &src)
	{
		this->_name = src._name;
		for (int i = 0; i < 4; i++)
		{
			delete this->_inventory[i];
			this->_inventory[i] = src._inventory[i]->clone();
		}
	}
	return *this;
}

void	Character::_addTrash(AMateria* m)
{
	int	i = 0;
	while (i < 42 && this->_trashBin[i] != 0)
	{
		i++;
	}
	if (i < 42)
		this->_trashBin[i] = m;
	else
	{
		delete m;
		std::cout << "thrash bin is full" << std::endl;
		exit(0);
	}
}

std::string const& Character::getName(void) const
{
	return this->_name;
}
	
void Character::equip(AMateria* m)
{
	int	i = 0;
	
	while (i < 4 && this->_inventory[i] != 0)
	{
		if (this->_inventory[i] == m)
			return;
		i++;
	}
	if (i < 4)
		this->_inventory[i] = m;
}

void Character::unequip(int idx)
{
	if (idx > 3 || idx < 0 || this->_inventory[idx] == 0)
		return;
	this->_addTrash(this->_inventory[idx]);
	this->_inventory[idx] = 0;
}
	
void Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || idx < 0 || this->_inventory[idx] == 0)
		return;
	this->_inventory[idx]->use(target);
}