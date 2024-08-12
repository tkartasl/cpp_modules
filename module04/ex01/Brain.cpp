/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:47:23 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/12 16:10:11 by tkartasl         ###   ########.fr       */
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
	static int	index;
	
	if (index > 99)
		index = 0;
	this->_ideas[index] =  new_idea;
	index++;
}

std::string* Brain::getIdeas(void)
{
	return this->_ideas;
}