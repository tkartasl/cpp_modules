/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:55:50 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/26 10:35:28 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>

Data::Data(void)
{
	return;
}

Data::Data(Data const& src)
{
	(void)src;
	return;
}

Data::~Data(void)
{
	return;
}

Data& Data::operator=(Data const& src)
{
	(void)src;
	return *this;
}

void Data::print(void)
{
	std::cout << "Hello world!!" << std::endl;
}