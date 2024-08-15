/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:45:54 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/14 16:20:38 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& src);
		~MateriaSource(void);
		MateriaSource& operator=(const MateriaSource& src);
	
		virtual void		learnMateria(AMateria*);
		virtual AMateria*	createMateria(std::string const & type);
	private:
		AMateria* _inventory[4];
};

#endif