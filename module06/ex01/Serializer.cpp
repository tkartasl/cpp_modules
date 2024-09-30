/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:38:03 by tkartasl          #+#    #+#             */
/*   Updated: 2024/09/30 13:13:26 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {}
Serializer::Serializer(Serializer const&) {}
Serializer::~Serializer(void) {}
Serializer& Serializer::operator=(Serializer const& src)
{
	(void)src;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{	
	return reinterpret_cast<uintptr_t>(ptr);	
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}