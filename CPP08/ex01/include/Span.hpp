#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <limits>
#include <exception>
#include <limits>
#include <cstdlib>
#include <iostream>

class Span
{
	private:
		std::vector<int> numbers;
		unsigned int max_size;
	
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& rhs);
		~Span();

		void addNumber(int number);
		
		template <typename Iterator>
		void addNumbers(Iterator begin, Iterator end);
		unsigned int shortestSpan();
		unsigned int longestSpan();

		class SpanException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#include "Span.tpp"

#endif
