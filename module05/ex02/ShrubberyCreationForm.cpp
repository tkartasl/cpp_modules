/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:52:31 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/27 10:38:07 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src) : AForm(src)
{
	return;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& src)
{
	if (this != &src)
		AForm::operator=(src);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return;
}

void	ShrubberyCreationForm::_runExecute(void) const
{
	std::ofstream outfile;
	std::string tree =
        "         ccee88oo\n"
        "  C8O8O8Q8PoOb o8oo  \n"
        " dOB69QO8PdUOpugoO9bD\n"
        "CgggbU8OU qOp qOdoUOdcb\n"
        "    6OuU  /p u gcoUodpP\n"
        "      \\\\\\//  /douUP\n" 
        "        \\\\\\////\n"
        "         |||/\\\n" 
        "         |||\\/\n"
        "         |||||\n"
        "   .....//||||\\....\n";
	
	outfile.open(this->_target + "_shrubbery");
	if (outfile.is_open())
		outfile << tree;
	outfile.close();
}
