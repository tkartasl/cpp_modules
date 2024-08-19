/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:09:33 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/16 19:13:48 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H
# include <string>
# include <iostream>

class Bureaucrat;

class AForm
{
	public:
		AForm(void);
		AForm(AForm const& src);
		AForm(const char* n, const int ts, const int te);
		virtual ~AForm(void);
		AForm& operator=(AForm const& src);

		const char*	getName(void) const;
		bool	isSigned(void) const;
		int	getGradeToSign(void) const;
		int	getGradeToExecute(void) const;
		void	beSigned(Bureaucrat const& b);
		virtual void execute(Bureaucrat const& executor) const;
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		const char* _name;
		bool	_signed;
		const int	_grade_to_sign;
		const int	_grade_to_execute;
		virtual void	_runExecute(void) const = 0;
};	

std::ostream & operator<<(std::ostream & o, AForm& f);

#endif