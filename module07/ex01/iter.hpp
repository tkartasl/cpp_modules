/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:59:44 by tkartasl          #+#    #+#             */
/*   Updated: 2024/09/02 13:18:35 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H
# include <iostream>
# include <array>

template<typename T>
void iter(T* array, size_t const len, void (*func)(T& a))
{
		for (size_t i = 0; i < len; i++)
		{
			func(array[i]);
		}
}

template<typename T>
void iter(const T* array, size_t const len, void (*func)(const T& a))
{
		for (size_t i = 0; i < len; i++)
		{
			func(array[i]);
		}
}

#endif