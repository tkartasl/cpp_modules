/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:47:32 by tkartasl          #+#    #+#             */
/*   Updated: 2024/11/04 13:10:15 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::~Span() {}

Span::Span(Span const& src) {
	*this = src;
}

Span& Span::operator=(Span const& src) {
	if (this != &src)
		this->_N = src._N;
	return *this;	
}

void	Span::addNumber(int number) {
	if (this->_span.size() < this->_N)
		this->_span.push_back(number);
	else
		throw Span::SpanIsFullException();
}

int	Span::shortestSpan() {
	std::vector<int> result;
	if (this->_span.size() <= 1)
		throw Span::NoSpanFoundException();
	std::adjacent_difference(this->_span.begin(), this->_span.end(), result);
	return *std::min_element(result.begin(), result.end());
}

int	Span::longestSpan() {
	if (this->_span.size() <= 1)
		throw Span::NoSpanFoundException();
	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> result = std::minmax_element(this->_span.begin(), this->_span.end());
	return (*result.second - *result.first);
}

void	Span::addMultipleNumbers(unsigned int amount) {
	std::vector<int>::iterator it;
	if (this->_span.size() == this->_N)
		throw Span::SpanIsFullException();
	for (it = this->_span.end(); it < this->_span.end() + amount; it ++) {
		
	}
}

const char* Span::SpanIsFullException::what() const throw()
{
	return "Span is already full\n";
}

const char* Span::NoSpanFoundException::what() const throw()
{
	return "No span can be found\n";
}