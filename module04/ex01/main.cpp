/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:52:07 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/12 16:13:52 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta[4] = {new Cat(), new Cat(), new Dog(), new Dog()};

	std::cout << meta[0]->getType() << std::endl;
	meta[0].setCatIdeas("I'm cute");

	for (int i = 0; i < 4; i++)
	{
		delete meta[i];
	}
	return (0);
}
