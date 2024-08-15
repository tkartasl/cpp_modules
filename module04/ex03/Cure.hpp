/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:18:38 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/14 16:40:32 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H
# include "AMateria.hpp"
# include "ICharacter.hpp"
 
class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(const Cure& src);
		~Cure(void);
		Cure& operator=(const Cure& src);	

		AMateria*	clone(void) const;
		void		use (ICharacter& target);
};

#endif