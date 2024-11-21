/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:01:42 by tkartasl          #+#    #+#             */
/*   Updated: 2024/11/19 09:53:00 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
	if (argc == 1) {
		std::cout << "Error: could not open file" << std::endl;
		return 1;
	}
	else if (argc > 2) {
		std::cout << "Error: too many arguments" << std::endl;
		return 1;
	}
	try {
		BitcoinExchange btc(argv[1]);	
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}