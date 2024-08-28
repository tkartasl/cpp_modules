/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:47:23 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/28 12:36:47 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain's constructor called" << std::endl;
	return;
}
	
Brain::Brain(Brain const& src)
{
	std::cout << "Brain's copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = src._ideas[i];
	}
}

Brain::~Brain(void)
{
	std::cout << "Brain's destructor called" << std::endl;
	return;
}
Brain& Brain::operator=(Brain const& src)
{
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
		{
			this->_ideas[i] = src._ideas[i];
		}
	}
	return *this;
}

void Brain::setIdeas(const std::string new_idea)
{
	for (int i = 0; i < 100; i++)
	{
		if (this->_ideas[i].empty())
		{
			this->_ideas[i] = new_idea;
			break;
		}
	}
}

std::string* Brain::getIdeas(void)
{
	return this->_ideas;
}