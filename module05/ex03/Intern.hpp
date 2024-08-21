/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:23:37 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/19 13:16:26 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H
# include <string>

class AForm;

class Intern
{
	public:
		Intern(void);
		Intern(Intern const& src);
		~Intern(void);
		Intern& operator=(Intern const& src);

		AForm*	makeForm(std::string name, std::string target);
};

#endif