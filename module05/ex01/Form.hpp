/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:09:33 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/16 18:41:02 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H
# include <string>
# include <iostream>

class Bureaucrat;

class Form
{
	public:
		Form(void);
		Form(const char* n, const int ts, const int te);
		Form(Form const& src);
		~Form(void);
		Form& operator=(Form const& src);

		const char*	getName(void) const;
		bool	isSigned(void) const;
		int	getGradeToSign(void) const;
		int	getGradeToExecute(void) const;
		void	beSigned(Bureaucrat const& b);

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

	private:
		const char* _name;
		bool	_signed;
		const int	_grade_to_sign;
		const int	_grade_to_execute;
};

std::ostream & operator<<(std::ostream & o, Form& f);

#endif