#include "Span.hpp"
#include <iostream>
#include <random>
#include <numeric>

int main() {
	Span test(5);
	for (int i = 0; i < 5; i++) {
			std::cout << (i) << std::endl;
			test.addNumber(i);
		}
	
	std::cout << "no exception yet??\n";
	std::cout << "Shortest span is " << test.shortestSpan() << std::endl;
	std::cout << "Longest span is " << test.longestSpan() << std::endl;
	try {
			test.addNumber(2);
	} catch (Span::SpanIsFullException& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Span Maxmin(2);
		Maxmin.addNumber(-2147483648);
		Maxmin.addNumber(2147483647);

		std::cout << "Shortest span is " << Maxmin.shortestSpan() << std::endl;
		std::cout << "Longest span is " << Maxmin.longestSpan() << std::endl;

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Span Maxmin(2);
		Maxmin.addNumber(2);

		std::cout << Maxmin.shortestSpan() << std::endl;
		std::cout << Maxmin.longestSpan() << std::endl;

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Span big(15000);
		std::vector<int> intVector;
		for (int i = 0; i < 15000; i++) {
			std::random_device dev;
			std::mt19937 rng(dev());
			std::uniform_int_distribution<std::mt19937::result_type> dist(INT32_MIN, INT32_MAX);
			intVector.push_back(dist(rng));
		}
		big.addRangeOfNumbers(intVector.begin(), intVector.end());
		std::cout << "Shortest span is " << big.shortestSpan() << std::endl;
		std::cout << "Longest Span is " << big.longestSpan() << std::endl;
		big.addNumber(3);
	} catch (Span::SpanIsFullException& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}