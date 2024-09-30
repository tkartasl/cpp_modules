/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:27:49 by tkartasl          #+#    #+#             */
/*   Updated: 2024/09/30 13:11:45 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data d;
	Data *e;
	
	d.i = 42;

	std::cout << &d << std::endl;
	uintptr_t raw = Serializer::serialize(&d);
	e = Serializer::deserialize(raw);
	std::cout << e << std::endl;

	std::cout << e->i << std::endl;
	return 0;
}