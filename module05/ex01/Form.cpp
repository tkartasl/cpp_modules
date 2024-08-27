/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:26:19 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/27 10:43:17 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name(""), _signed(false), _grade_to_sign(1), _grade_to_execute(1)
{
	return;
}
Form::Form(const char* n, const int ts, const int te) : _name(n), _signed(false), _grade_to_sign(ts), _grade_to_execute(te)
{
	if (this->_grade_to_sign < 1 || this->_grade_to_execute < 1)
		throw Form::GradeTooHighException();
	if (this->_grade_to_sign > 150 || this->_grade_to_execute > 150)
		throw Form::GradeTooLowException();
	return;
}

Form::Form(Form const& src) : _grade_to_sign(1), _grade_to_execute(1)
{
	this->_signed = src._signed;
	return;
}

Form::~Form(void)
{
	return;
}

Form& Form::operator=(Form const& src)
{
	if (this != &src)
		this->_signed = src._signed;
	return *this;
}

const char*	Form::getName(void) const
{
	return this->_name;
}

bool	Form::isSigned(void) const
{
	return this->_signed;
}

int	Form::getGradeToSign(void) const
{
	return this->_grade_to_sign;
}

int	Form::getGradeToExecute(void) const
{
	return this->_grade_to_execute;
}

void	Form::beSigned(Bureaucrat const& b)
{
	if (b.getGrade() <= this->_grade_to_sign)
		this->_signed = true;
	else
		throw Form::GradeTooLowException(); 
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream & operator<<(std::ostream & o, Form& f)
{
	o << "Form " << f.getName() << " is signed? " <<  f.isSigned() << ", grade to sign is " << f.getGradeToSign() << ", grade to execute is " << f.getGradeToExecute();
	return o;
}