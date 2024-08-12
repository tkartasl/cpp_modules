/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:17:05 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/12 11:59:57 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
# define WRONGCAT_H
# include "WrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal
{
public:
	WrongCat(void);
	WrongCat(WrongCat const& src);
	~WrongCat(void);
	WrongCat& operator=(WrongCat const& src);

	void makeSound(void) const;
};

#endif