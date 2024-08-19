/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:44:14 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/16 18:34:06 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : _name(""), _grade(1)
{
	return;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return;	
}

Bureaucrat::Bureaucrat(Bureaucrat const& src)
{
	this->_grade = src._grade;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& src)
{
	if (this != &src)
		this->_grade = src._grade;
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
	return;
}

const std::string	Bureaucrat::getName(void) const
{
	return this->_name;
}

int	Bureaucrat::getGrade(void) const
{
	return this->_grade; 
}

void	Bureaucrat::improveGrade(void)
{
	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::lowerGrade(void)
{
	this->_grade++;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::signForm(Form& f)
{
	if (this->_grade <= f.getGradeToSign())
	{
		std::cout << this->_name << " signed " << f.getName() << std::endl;	
		f.beSigned(*this);
	}
	else
	{
		std::cout << this->_name << " couldn't sign ";
		std::cout << f.getName() << " because ";
		f.beSigned(*this); 
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & b)
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade();
	return o;
}