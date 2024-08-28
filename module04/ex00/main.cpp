/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:52:07 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/28 12:40:27 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* w = new WrongCat();
	const Animal& cat = Cat();
	const Animal& dog = Dog();
	const Cat o = Cat();
	const Dog d = Dog();
	const Animal* PTRcat = &o;
	const Animal* PTRdog = &d;

	std::cout << "Animal j is a " << j->getType() << " " << std::endl;
	std::cout << "Animal i is a " << i->getType() << " " << std::endl;
	std::cout << "Animal meta is a " << meta->getType() << " " << std::endl;
	std::cout << "Animal cat is a " << cat.getType() << " " << std::endl;
	std::cout << "Animal dog is a " << dog.getType() << " " << std::endl;
	std::cout << "Animal PTRcat is a " << PTRcat->getType() << " " << std::endl;
	std::cout << "Animal PTRdog is a " << PTRdog->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	cat.makeSound();
	dog.makeSound();
	PTRcat->makeSound();
	PTRdog->makeSound();
	w->makeSound();
		
	delete j;
	delete i;
	delete w;
	delete meta;
	return (0);
}