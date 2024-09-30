/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:24:20 by tkartasl          #+#    #+#             */
/*   Updated: 2024/09/30 12:19:44 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
	return;
}

Intern::Intern(Intern const& src)
{
	(void)src;
	return;
}

Intern::~Intern(void)
{
	return;
}

Intern& Intern::operator=(Intern const& src)
{
	(void)src;
	return *this;
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	const char*	forms[4] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm", "none"};
	int	i = 0;
	AForm* form = nullptr;

	while (i < 3)
	{
		if (name == forms[i])
			break;
		i++;	
	}
	switch(i)
	{
		case 0: 
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		case 3:
			std::cout << name << " form doesn't exist" << std::endl;
			return form;
	}
	std::cout << "Intern signed " << form->getName() << std::endl;
	return form;
}