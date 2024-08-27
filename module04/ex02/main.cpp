/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:52:07 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/27 10:19:03 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	try
	{
		const Animal* i = new Cat();
		const Animal* j = new Dog();
		//const Animal  a = Animal();
		const Animal* meta[4] = {new Cat(), new Cat(), new Dog(), new Dog()};
		
		const Cat c = Cat();
		const Dog d = Dog();
		const Dog copy = Dog(d);
		delete i;
		delete j;

		d.getBrains()->setIdeas("I want a bone");
		d.getBrains()->setIdeas("Why I have four legs??");
		d.getBrains()->setIdeas("I wanna go outside and play with other dogs");
		copy.getBrains()->setIdeas("I am a copy");

		std::cout << copy.getBrains()->getIdeas()[0] << " of a " << copy.getType() << std::endl;
		for (int i = 0; !d.getBrains()->getIdeas()[i].empty(); i++)
			std::cout << d.getBrains()->getIdeas()[i] << std::endl;
		
		d.makeSound();
		
		c.getBrains()->setIdeas("I want food");
		c.getBrains()->setIdeas("I am cute");
		c.getBrains()->setIdeas("I wanna drop something and make noise");

		for (int i = 0; !c.getBrains()->getIdeas()[i].empty(); i++)
		std::cout << c.getBrains()->getIdeas()[i] << std::endl;

		c.makeSound();
		
		for (int i = 0; i < 4; i++)
		{
		std::cout << meta[i]->getType() << std::endl;
		delete meta[i];
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
