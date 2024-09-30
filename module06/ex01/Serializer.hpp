/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:31:26 by tkartasl          #+#    #+#             */
/*   Updated: 2024/09/30 13:09:49 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
# define SERIALIZER_H
# include <cstdint>

struct Data
{
	int i;
};

class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	private:
		Serializer(void);
		Serializer(Serializer const& src);
		~Serializer(void);
		Serializer& operator=(Serializer const& src);
};

#endif