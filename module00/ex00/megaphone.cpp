/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:27:52 by tkartasl          #+#    #+#             */
/*   Updated: 2024/08/07 15:21:58 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
	int	i;
	std::string input_str;
	std::string output_str;
	const char* whitespace = " \t\n\r\f\v";

	i = 1;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return(0);
	}
	while (argv[i] != 0)
	{
		input_str = argv[i];
		input_str.erase(input_str.find_last_not_of(whitespace) + 1);
		input_str.erase(0, input_str.find_first_not_of(whitespace));
		for (char ch : input_str)
			output_str += std::toupper(ch);
		if (!input_str.empty())
			output_str += " ";
		i++;
	}
	output_str.pop_back();
	std::cout << output_str << std::endl;
	return (0);
}

