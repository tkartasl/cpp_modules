/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:56:01 by tkartasl          #+#    #+#             */
/*   Updated: 2024/11/21 10:57:33 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string path) : _path(path) {
	_loadInput();
	_loadDatabase();
}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(BitcoinExchange const& src) {
	this->_path = src._path;
	this->_input = src._input;
	this->_database = src._database;	
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& src) {
	if (this != &src) {
		this->_path = src._path;
		this->_input = src._input;
		this->_database = src._database;	
	}
	return *this;
}

void BitcoinExchange::_parseInputLine(std::string buffer) {
	std::string date;
	std::string value;
	size_t		index;
	s_data		data = {};

	index = buffer.find(" ");
	date = buffer.substr(0, index);
	index = buffer.find("|");
	if (date.length() != 10 || index == std::string::npos) {
		data.error = "Error: bad input => " + buffer;
		return;
	}
	index = buffer.find_first_not_of(" ", index + 1);
	if (index == std::string::npos) {
		data.error = "Error: bad input => " + buffer;
		return;
	}
	
}

void BitcoinExchange::_loadInput() {
	std::ifstream inFile;
	std::string   buffer;

	inFile.open(_path);
	if (inFile.is_open()) {
		int line = 0;
		while (std::getline(inFile, buffer)) {
			if (line > 0) {
				_parseInputLine(buffer);
			}
			line++;
		}
	}
	else {
		throw BitcoinExchange::UnableToOpenFileException();	
	}
}

void BitcoinExchange::_loadDatabase() {
	
}

const char* BitcoinExchange::UnableToOpenFileException::what() const throw()
{
	return "Error: could not open file";
}