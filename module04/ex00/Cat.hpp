/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:42:09 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/12 11:59:42 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H
# include "Animal.hpp"

class Cat : virtual public Animal
{
public:
	Cat(void);
	Cat(Cat const& src);
	~Cat(void);
	Cat& operator=(Cat const& src);

	void makeSound(void) const;
};

#endif