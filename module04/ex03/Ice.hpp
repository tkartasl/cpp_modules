/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:07:02 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/14 16:40:45 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(const Ice& src);
		~Ice(void);
		Ice& operator=(const Ice& src);	

		AMateria*	clone(void) const;
		void		use (ICharacter& target);
};

#endif