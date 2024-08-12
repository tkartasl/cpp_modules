/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:27:40 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/12 11:51:23 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H
# include <iostream>

class Animal
{
public:
	Animal(void);
	Animal(Animal const& src);
	virtual ~Animal(void);
	Animal& operator=(Animal const &src);

	std::string getType(void) const;
	virtual void makeSound(void) const;
protected:
	std::string _type;
};

#endif