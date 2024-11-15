/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:47:32 by tkartasl          #+#    #+#             */
/*   Updated: 2024/11/15 14:27:44 by tkartasl         ###   ########.fr       */
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

long	Span::shortestSpan() {
	if (this->_span.size() <= 1)
		throw Span::NoSpanFoundException();

	std::vector<long> sorted = this->_span;
	std::sort(sorted.begin(), sorted.end());
	long result = __LONG_MAX__;
	for (size_t i = 1; i < sorted.size(); ++i) {
		long diff = std::abs(sorted[i] - sorted[i - 1]);
		if (diff < result)
			result = diff;
	}
	return result;
}

long	Span::longestSpan() {
	if (this->_span.size() <= 1)
		throw Span::NoSpanFoundException();
	std::pair<std::vector<long>::iterator, std::vector<long>::iterator> result = std::minmax_element(this->_span.begin(), this->_span.end());
	return (*result.second - *result.first);
}

const char* Span::SpanIsFullException::what() const throw() {
	return "Span is already full";
}

const char* Span::NoSpanFoundException::what() const throw() {
	return "No span can be found";
}