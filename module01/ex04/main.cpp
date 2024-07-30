/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:58:00 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/30 15:58:02 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
	//std::ifstream 	infile;
	//std::ofstream 	outfile;
	std::string	filename;
	std::string	str1;
	std::string	str2;
	std::string	line;
	std::size_t	index = 0;
	std::size_t	prevIndex = 0;

	if (argc != 4)
	{
		std::cout << "This program takes 3 arguments (filename, string1, string2)" << std::endl;
		return (1);
	}
	filename = argv[1];
	str1 = argv[2];
	str2 = argv[3];
	std::ifstream infile(filename);
	std::ofstream outfile(filename.append(".replace"));
	if (infile.is_open() && outfile.is_open())
	{
		while (std::getline(infile, line))
		{
			prevIndex = index;
			index = line.find(str2);
			if (index != std::string::npos)
			{
				line.substr(prevIndex, index);
				line.append(str2);
				outfile << line;
			}
			else
				outfile << line;
			index++;
		}
	}
	else
		std::cout << "Error while opening file" << std::endl;
	infile.close();
	std::cout << outfile << std::endl;
	outfile.close();
	return (0);
}