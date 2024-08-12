/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:51:14 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/12 11:59:49 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H
# include "Animal.hpp"

class Dog : virtual public Animal
{
public:
	Dog(void);
	Dog(Dog const& src);
	~Dog(void);
	Dog& operator=(Dog const& src);

	void makeSound(void) const;
};

#endif