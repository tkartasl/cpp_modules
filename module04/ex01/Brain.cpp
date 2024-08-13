/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:47:23 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/13 12:11:50 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	return;
}
	
Brain::Brain(Brain const& src)
{
	for (int i = 0; i < 99; i++)
	{
		this->_ideas[i] = src._ideas[i];
	}
}

Brain::~Brain(void)
{
	return;
}
Brain& Brain::operator=(Brain const& src)
{
	if (this != &src)
	{
		for (int i = 0; i < 99; i++)
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