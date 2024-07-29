/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:27:52 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/24 11:46:58 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
	int	i;
	std::string input_str;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	while (argv[i] != 0)
	{
		if (i > 1)
			input_str += " ";
		input_str += argv[i];
		i++;
	}
	i = 0;
	while (input_str[i] != 0)
	{
		input_str[i] = toupper(input_str[i]);
		i++;
	}
	std::cout << input_str << std::endl;
}
