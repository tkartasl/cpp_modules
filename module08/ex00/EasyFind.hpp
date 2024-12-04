/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:24:19 by tkartasl          #+#    #+#             */
/*   Updated: 2024/12/02 13:56:54 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H
# include <algorithm>


template<typename T>
typename T::iterator	easyfind(T& a, int i)
{
	return std::find(a.begin(), a.end(), i) != a.end()
}

#endif