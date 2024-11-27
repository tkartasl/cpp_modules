/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:56:01 by tkartasl          #+#    #+#             */
/*   Updated: 2024/11/27 15:53:21 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string path) : _path(path) {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& src) {
	this->_path = src._path;
	this->_database = src._database;	
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& src) {
	if (this != &src) {
		this->_path = src._path;
		this->_database = src._database;	
	}
	return *this;
}

void BitcoinExchange::getRates() {
	try {
		_loadDatabase();
		_readInputfile();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

bool BitcoinExchange::_validateDateSyntax(std::string& date) {
	
	if (date.length() != 10)
		return false;

	for (int i = 0; i < (int)date.length(); i++) {
		if (!std::isdigit(date[i]) && date[i] != '-')
			return false;
		else if (date[i] == '-' && i != 4 && i != 7)
			return false;
	}	
	return true;
}

bool BitcoinExchange::_validateValueSyntax(std::string& value) {
	int dotCount = 0;

	for (int i = 0; i < (int)value.length(); i++) {
		if (!std::isdigit(value[i]) && value[i] != '-' && value[i] != '.')
			return false;
		else if (value[i] == '-' && i != 0)
			return false;
		if (value[i] == '.') {
			dotCount++;
			if (i == (int)value.length() - 1)
				return false;
		}	
	}
	if (dotCount > 1)
		return false;
	return true;
}

void BitcoinExchange::_checkLeapYear(s_data& data, int& errorFlag) {
	bool isLeapYear = (data.year % 4 == 0 && data.year % 100 != 0) || data.year % 400 == 0;
	
	if (isLeapYear == true) {
		if (data.day > 29)
			errorFlag = SET;
	}
	else {
		if (data.day > 28)
			errorFlag = SET;
	}
}

void BitcoinExchange::_validateDay(s_data& data, int& errorFlag) {
	int longMonths[7] = {JANUARY, MARCH, MAY, JULY, AUGUST, OCTOBER, DECEMBER};
	int index;

	for (index = 0; index < 7; index++) {
		if (data.month == longMonths[index])
			break;
	}
	
	if (index == 7 && data.day > 30)
		errorFlag = SET;
	else {
		if (data.day > 31)
			errorFlag = SET;
	}
}

bool BitcoinExchange::_validateDateAndValue(s_data& data, std::string& input) {
	time_t currentTime = time(0);
	tm* now = localtime(&currentTime);
	int errorFlag = NOTSET;
	
	if (data.month < 1 || data.month > 12 || data.day < 1)
		errorFlag = SET;
		
	if (data.year > now->tm_year + 1900)
		errorFlag = SET;
	else if (data.year == now->tm_year + 1900 && data.month > now->tm_mon + 1)
		errorFlag = SET;
	else if (data.year == now->tm_year + 1900 && data.month == now->tm_mon + 1 && data.day > now->tm_mday)
		errorFlag = SET;
		
	if (data.year < 2009)
		errorFlag = SET;
	else if (data.year == 2009 && data.month == 1 && data.day < 2)
		errorFlag = SET;
	
	if (data.month == FEBRUARY)
		_checkLeapYear(data, errorFlag);
	else
		_validateDay(data, errorFlag);
	
	if (errorFlag == SET) {
		std::cout << "Error: bad input => " + input << std::endl;
		return false;
	}
	
	if (data.value < 0.0f) {
		std::cout << "Error: not a positive number.\n";
		return false;
	}
	else if (data.value > 1000.0f) {
		std::cout << "Error: too large number.\n";
		return false;
	}
	return true;
}

bool BitcoinExchange::_validateInputLine(std::string& separator, std::string& value, s_data& data) {
	std::string input = data.dateStr + separator + value;

	if (separator != " | ") {
		std::cout << "Error: bad input => " + input << std::endl;
		return false;
	}
	if (!_validateDateSyntax(data.dateStr) || !_validateValueSyntax(value)) {
		std::cout << "Error: bad input => " + input << std::endl;
		return false;
	}
	try {
		data.year = stoi(data.dateStr.substr(0, 4));
		data.month = stoi(data.dateStr.substr(5, 7));
		data.day = stoi(data.dateStr.substr(8, 10));
		data.value = stof(value);
		data.date = data.year * 10000 + data.month * 100 + data.day;
		if (!_validateDateAndValue(data, input)) {
			return false;
	}
	} catch (std::exception& e) {
		throw;
	}
	return true;
}

void BitcoinExchange::_findExchangeRate(s_data& data) {
	if (_database.find(data.date) != _database.end())
		std::cout << data.dateStr << " => " << data.value << " = " << data.value * _database[data.date] << std::endl;
	else {
		std::map<int, float>::reverse_iterator it;
		for (it = _database.rbegin(); it != _database.rend(); it++) {
			if (it->first < data.date) {
				std::cout << data.dateStr << " => " << data.value << " = " << static_cast<float>(data.value * it->second) << std::endl;
				break;
			}
		}
	}
}

void BitcoinExchange::_parseInputLine(std::string& buffer) {
	std::string date;
	std::string value;
	std::string separator;
	size_t		index;
	size_t 		end;
	s_data		data = {};

	try {
		index = buffer.find(" ");
		if (index == std::string::npos) {
			std::cout << "Error: bad input => " + buffer << std::endl;
			return;
		}
		end = buffer.find("\n");
		data.dateStr = buffer.substr(0, index);
		if (index + 3 < buffer.length()) {
			separator = buffer.substr(index, 3);
			value = buffer.substr(index + 3, end);
		}
		if (!_validateInputLine(separator, value, data))
			return;
		else
			_findExchangeRate(data);
		} catch (std::exception& e) {
		throw;
	}
}

void BitcoinExchange::_readInputfile() {
	std::ifstream inFile;
	std::string   buffer;

	try {
		inFile.open(_path);
		if (inFile.is_open()) {
			int lineNumber = 0;
			while (std::getline(inFile, buffer)) {
				if (lineNumber == 0 && buffer != "date | value")
					throw BitcoinExchange::InvalidInputfileException();
				else if (lineNumber > 0)
					_parseInputLine(buffer);
				lineNumber++;
			}
		}
		else {
			throw BitcoinExchange::UnableToOpenFileException();	
		}
	} catch (std::exception& e) {
		throw;
	}
}

void BitcoinExchange::_parseDatabaseLine(std::string& buffer) {
	try {
		size_t 		separator = buffer.find(",");
		std::string dateStr = buffer.substr(0, separator);
		float rate = stof(buffer.substr(separator + 1, std::string::npos));
		
		int year = stoi(dateStr.substr(0, 4));
		int month = stoi(dateStr.substr(5, 7));
		int day = stoi(dateStr.substr(8, 10));
		int date = year * 10000 + month * 100 + day;
		_database[date] = rate;
	} catch (std::exception& e) {
		throw ;
	}
}

void BitcoinExchange::_loadDatabase() {
	std::ifstream inFile;
	std::string   buffer;

	try {
		inFile.open("data.csv");
		if (inFile.is_open()) {
			while (std::getline(inFile, buffer)) {
				if (buffer != "date,exchange_rate") {
					_parseDatabaseLine(buffer);
				}
			}
		}
		else {
			throw BitcoinExchange::UnableToOpenFileException();	
		}	
	} catch (std::exception& e) {
		throw ;
	}
}

const char* BitcoinExchange::UnableToOpenFileException::what() const throw()
{
	return "Error: could not open file";
}

const char* BitcoinExchange::InvalidInputfileException::what() const throw()
{
	return "Error: invalid input file";
}