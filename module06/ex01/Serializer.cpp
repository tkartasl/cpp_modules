/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:38:03 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/22 15:01:31 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t serialize(Data* ptr)
{	
	return static_cast<uintptr_t>(ptr);	
}

Data* deserialize(uintptr_t raw)
{
	return static_cast<Data *>(raw);
}