/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:26:19 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/16 13:23:06 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name(""), _signed(false), _grade_to_sign(1), _grade_to_execute(1)
{
	return;
}

AForm::AForm(const char* n, const int ts, const int te) : _name(n), _signed(false), _grade_to_sign(ts), _grade_to_execute(te)
{
	if (this->_grade_to_sign < 1 || this->_grade_to_execute < 1)
		throw AForm::GradeTooHighException();
	if (this->_grade_to_sign > 150 || this->_grade_to_execute > 150)
		throw AForm::GradeTooLowException();
	return;
}

AForm::AForm(AForm const& src) : _grade_to_sign(1), _grade_to_execute(1)
{
	this->_signed = src._signed;
	return;
}

AForm::~AForm(void)
{
	return;
}

AForm& AForm::operator=(AForm const& src)
{
	if (this != &src)
		this->_signed = src._signed;
	return *this;
}

const char*	AForm::getName(void) const
{
	return this->_name;
}

bool	AForm::isSigned(void) const
{
	return this->_signed;
}

int	AForm::getGradeToSign(void) const
{
	return this->_grade_to_sign;
}

int	AForm::getGradeToExecute(void) const
{
	return this->_grade_to_execute;
}

void	AForm::beSigned(Bureaucrat const& b)
{
	if (b.getGrade() <= this->_grade_to_sign)
		this->_signed = true;
	else
		throw AForm::GradeTooLowException(); 
}

void	AForm::execute(Bureaucrat const& executor) const
{
	if (this->_signed == false)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->_grade_to_execute)
		throw AForm::GradeTooLowException();
	else
		this->_runExecute();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

std::ostream & operator<<(std::ostream & o, AForm& f)
{
	o << "AForm " << f.getName() << " is signed? " <<  f.isSigned();
	o << ", grade to sign is " << f.getGradeToSign();
	o << ", grade to execute is " << f.getGradeToExecute();
	return o;
}