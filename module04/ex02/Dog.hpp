/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:51:14 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/13 15:23:59 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(Dog const& src);
		~Dog(void);
		Dog& operator=(Dog const& src);

		Brain*	getBrains(void) const;
		virtual void	makeSound(void) const;
	private:
		Brain* _brainPTR;
};

#endif