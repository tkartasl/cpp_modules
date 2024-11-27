/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:56:03 by tkartasl          #+#    #+#             */
/*   Updated: 2024/11/27 14:29:23 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <fstream>
# include <map>
# include <ctime>

typedef struct t_data {
	int day;
	int month;
	int year;
	int date;
	float value;
	std::string dateStr;
} s_data;

typedef enum t_flag {
	NOTSET,
	SET	
} e_flag;

typedef enum t_months {
	JANUARY = 1,
	FEBRUARY = 2,
	MARCH = 3,
	APRIL = 4,
	MAY = 5,
	JUNE = 6,
	JULY = 7,
	AUGUST = 8,
	SEPTEMBER = 9,
	OCTOBER = 10,
	N0VEMBER = 11,
	DECEMBER = 12	
} e_months;

class BitcoinExchange {
	public:
		BitcoinExchange(std::string);
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const&);
		BitcoinExchange& operator=(BitcoinExchange const&);
		
		void getRates();
		
	private:
		std::string _path;
		void _readInputfile();
		void _loadDatabase();
		void _parseInputLine(std::string&);
		void _parseDatabaseLine(std::string&);
		bool _validateInputLine(std::string&, std::string&, s_data&);
		bool _validateDateSyntax(std::string&);
		bool _validateValueSyntax(std::string&);
		bool _validateDateAndValue(s_data&, std::string&);
		void _checkLeapYear(s_data&, int&);
		void _validateDay(s_data&, int&);
		void _findExchangeRate(s_data&);
		std::map <int, float> _database;

	class UnableToOpenFileException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class InvalidInputfileException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif