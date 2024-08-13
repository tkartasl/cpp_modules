/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:52:07 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/13 15:59:40 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	
	const Animal* meta[4] = {new Cat(), new Cat(), new Dog(), new Dog()};
	
	const Cat c = Cat();
	const Dog d = Dog();
	delete i;
	delete j;

	d.getBrains()->setIdeas("I want a bone");
	d.getBrains()->setIdeas("Why I have four legs??");
	d.getBrains()->setIdeas("I wanna go outside and play with other dogs");

	const Dog copy = d;
	for (int i = 0; !copy.getBrains()->getIdeas()[i].empty(); i++)
		std::cout << copy.getBrains()->getIdeas()[i] << std::endl;
	
	copy.getBrains()->setIdeas("new idea");
	
	for (int i = 0; !d.getBrains()->getIdeas()[i].empty(); i++)
		std::cout << d.getBrains()->getIdeas()[i] << std::endl;
	
	for (int i = 0; !copy.getBrains()->getIdeas()[i].empty(); i++)
		std::cout << copy.getBrains()->getIdeas()[i] << std::endl;
	
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
	return (0);
}
