/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:06:11 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/14 17:48:36 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

int main()
{
	try
	{
		IMateriaSource* src = new MateriaSource();
		IMateriaSource* s = new MateriaSource();
		AMateria* arr[10];
		s->createMateria("snow");
		s->createMateria("ice");
		AMateria* i;
		s->learnMateria(new Ice());
		i = s->createMateria("ice");
		
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		
		
		ICharacter* me = new Character("me");
		AMateria* tmp;
		
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		for (int i = 0; i < 10; i++)
		{
			arr[i] = src->createMateria("cure");
		}
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(5, *bob);
		me->equip(tmp);
		for (int i = 0; i < 10; i++)
		{
			me->equip(arr[i]);
			me->unequip(0);	
		}
		bob->equip(i);
		bob->use(0, *me);
		delete bob;
		delete me;
		delete src;
		delete s;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}