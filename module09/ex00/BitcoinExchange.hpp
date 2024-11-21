/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:56:03 by tkartasl          #+#    #+#             */
/*   Updated: 2024/11/21 10:46:10 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXHANGE_HPP
# include <iostream>
# include <fstream>
# include <vector>

typedef struct t_data {
	int day;
	int month;
	int year;
	float value;
	std::string date;
	std::string error;
} s_data;

class BitcoinExchange {
	public:
		BitcoinExchange(std::string path);
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const& src);
		BitcoinExchange& operator=(BitcoinExchange const& src);
		
	private:
		std::string _path;
		void _loadInput();
		void _loadDatabase();
		void _parseInputLine(std::string);
		std::vector <s_data> _input;
		std::vector <s_data> _database;

	class UnableToOpenFileException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif