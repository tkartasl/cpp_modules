/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:21:25 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/14 16:24:41 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character(void);
		Character(std::string const name);
		Character(const Character& src);
		~Character(void);
		Character& operator=(const Character& src);

		virtual std::string const& getName(void) const;
		virtual void	equip(AMateria* m);
		virtual void	unequip(int idx);
		virtual void	use(int idx, ICharacter& target);
	private:
		AMateria* _inventory[4];
		AMateria* _trashBin[42];
		std::string _name;
		void	_addTrash(AMateria* m);
};

#endif