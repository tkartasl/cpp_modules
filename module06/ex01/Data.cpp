/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:55:50 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/22 14:58:24 by tkartasl         ###   ########.fr       */
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

void print(void)
{
	std::cout << "Hello world!!" << std::endl;
}