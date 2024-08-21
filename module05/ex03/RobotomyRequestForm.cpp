/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:21:04 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/16 19:11:21 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src)
{
	this->_target = src._target;
	return;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& src)
{
	if (this != &src)
		this->_target = src._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return;
}

void	RobotomyRequestForm::_runExecute(void) const
{
	static int	counter;
	
	if (counter == 100)
		counter = 0;
	std::cout <<"*Drilling noises*" << std::endl;
	if (counter & 1)
		std::cout << this->_target << " has been robotomized succesfully" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
	counter++;
}