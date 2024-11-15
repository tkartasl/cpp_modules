/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:47:48 by tkartasl          #+#    #+#             */
/*   Updated: 2024/11/15 14:28:36 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <exception>
# include <algorithm>
# include <numeric>

class Span {
	
	public:
		Span(unsigned int N);
		~Span();
		Span(Span const& src);
		Span& operator=(Span const& src);
		
		void	addNumber(int number);
		long	shortestSpan();
		long	longestSpan();
		class SpanIsFullException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class NoSpanFoundException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		template<typename Iterator>
		void	addRangeOfNumbers(Iterator first, Iterator last) {
			if (std::distance(first, last) > static_cast<long>(_N - _span.size()))
				throw Span::SpanIsFullException();
			for(Iterator it = first; it != last; ++it) {
				_span.push_back(*it);	
			}
		};
	private:
		unsigned int _N;
		std::vector<long> _span;		
};

#endif