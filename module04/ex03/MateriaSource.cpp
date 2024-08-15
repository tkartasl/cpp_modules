/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:44:01 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/14 17:26:51 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : IMateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = 0;
	}
	return;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	for (int i = 0; i < 4; i++)
	{
		delete this->_inventory[i];
		this->_inventory[i] = src._inventory[i]->clone();
	}
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		delete this->_inventory[i];
	}
	return;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src)
{
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			delete this->_inventory[i];
			this->_inventory[i] = src._inventory[i]->clone();
		}
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria* m)
{
	int	i = 0;
	
	while (i < 4 && this->_inventory[i] != 0)
	{
		i++;
	}
	if (i < 4)
	{
		this->_inventory[i] = m->clone();
	}
	delete m;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	int	i = 3;

	while (i >= 0)
	{
		if (this->_inventory[i] != 0)
			if (this->_inventory[i]->getType() == type)
				return this->_inventory[i]->clone();
		i--;
	}
	return 0;
}