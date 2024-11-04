/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:47:48 by tkartasl          #+#    #+#             */
/*   Updated: 2024/11/04 13:05:08 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <exception>
# include <algorithm>
# include <utility>
# include <numeric>

class Span {
	
	public:
		Span(unsigned int N);
		~Span();
		Span(Span const& src);
		Span& operator=(Span const& src);
		
		void	addNumber(int number);
		int		shortestSpan();
		int		longestSpan();
		void	addMultipleNumbers(unsigned int amount);
	
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
	private:
		unsigned int _N;
		std::vector<int> _span;		
};

#endif