/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:09:49 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/13 13:23:20 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H
# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const& src);
		virtual ~WrongAnimal(void);
		WrongAnimal& operator=(WrongAnimal const &src);

		std::string getType(void) const;
		virtual void makeSound(void) const;
	protected:
		std::string _type;
};

#endif