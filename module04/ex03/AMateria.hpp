/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:40:06 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/13 13:22:30 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H
# include <string>

class AMateria
{
	public:
		AMateria(std::string const& type);
		AMateria(void);
		AMateria(const AMateria& src);
		virtual ~AMateria(void);
		AMateria& operator=(const AMateria& src);

		std::string const& getType(void) const;
		virtual AMateria* clone(void) const = 0;
		virtual	void use (ICharacter& target);
	protected:
		std::string _type;
};



#endif