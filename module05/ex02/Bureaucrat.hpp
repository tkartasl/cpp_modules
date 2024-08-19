/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:27:59 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/16 18:38:48 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H
# include <iostream>
# include <exception>

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(Bureaucrat const& src);
		Bureaucrat& operator=(Bureaucrat const& src);
		~Bureaucrat(void);
		
		const std::string	getName(void) const;
		int	getGrade(void) const;
		void	improveGrade(void);
		void	lowerGrade(void);
		void	signForm(AForm& f);
		void	executeForm(AForm const& form) const;
	
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
		const std::string _name;
		int	_grade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const& b);

#endif