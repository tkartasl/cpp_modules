/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:26:06 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/31 18:57:57 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl esko;

	esko.complain("DEBUG");
	esko.complain("INFO");
	esko.complain("WARNING");
	esko.complain("ERROR");
	esko.complain("LOL");
	return (0);
}