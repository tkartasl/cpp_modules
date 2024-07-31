/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:26:06 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/31 20:21:28 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char* argv[])
{
	std::string	level;
	Harl 		h;
	if (argc != 2)
	{
		std::cout << "Wrong amount of arguments (1 required)" << std::endl;
		return (1);
	}
	level = argv[1];
	h.complain(level);
	return (0);
}