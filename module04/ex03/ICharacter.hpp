/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:36:58 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/14 16:29:07 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_H
# define ICHARACTER_H

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter(void) {}
		virtual std::string const& getName(void) const = 0;
		virtual void 	equip(AMateria* m) = 0;
		virtual void 	unequip(int idx) = 0;
		virtual void 	use(int idx, ICharacter& target) = 0;
};

#endif