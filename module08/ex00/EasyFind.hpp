/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:24:19 by tkartasl          #+#    #+#             */
/*   Updated: 2024/11/04 11:40:44 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H
# include <algorithm>
# include <exception>
# include <iostream>

template<typename T>
void	easyfind(T& a, int i)
{
	if (std::find(a.begin(), a.end(), i) != a.end())
		std::cout << "Found " << i << std::endl;
	else
		throw std::exception();
}

#endif