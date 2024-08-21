/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:39:06 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/19 13:59:46 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
		public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const& src);
		PresidentialPardonForm& operator=(PresidentialPardonForm const& src);
		~PresidentialPardonForm(void);
	private:
		std::string _target;
		void	_runExecute(void) const;
};

#endif