/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:26:06 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/14 12:12:51 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl esko;

	try
	{
		esko.complain("DEBUG");
		esko.complain("INFO");
		esko.complain("WARNING");
		esko.complain("ERROR");
		esko.complain("LOL");
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}