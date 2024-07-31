/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:58:00 by tkartasl          #+#    #+#             */
/*   Updated: 2024/07/31 15:35:42 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
	std::ifstream 	infile;
	std::ofstream 	outfile;
	std::string		filename;
	std::string		filename2;
	std::string		str1;
	std::string		str2;
	std::string		buffer;
	std::size_t		pos = 0;

	if (argc != 4)
	{
		std::cout << "This program takes 3 arguments (filename, string1, string2)" << std::endl;
		return (1);
	}
	filename = argv[1];
	filename2 = filename + ".replace";
	str1 = argv[2];
	str2 = argv[3];
	infile.open(filename);
	outfile.open(filename2);
	if (infile.is_open() && outfile.is_open())
	{
		while (std::getline(infile, buffer))
		{
			while (pos != std::string::npos)
			{
				pos = buffer.find(str1, pos);
				if (pos != std::string::npos)
				{
					buffer.erase(pos, str1.length());
					buffer.insert(pos, str2);	
				}
			}
			outfile << buffer;
		}
	}
	else
		std::cout << "Error while opening file" << std::endl;
	infile.close();
	outfile.close();
	return (0);
}