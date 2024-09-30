/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:03:38 by tkartasl          #+#    #+#             */
/*   Updated: 2024/09/30 13:03:42 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Wrong amount of argmuents" << std::endl; 
		return (1);
	}
	ScalarConversion::convert(argv[1]);
}