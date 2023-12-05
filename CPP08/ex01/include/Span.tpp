#include "Span.hpp"

Span::Span() : max_size(0)
{

}

Span::Span(unsigned int N) : max_size(N)
{

}

Span::Span(const Span& other) : numbers(other.numbers), max_size(other.max_size)
{

}

Span& Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		this->numbers = rhs.numbers;
		this->max_size = rhs.max_size;
	}
	return *this;
}

Span::~Span()
{

}

void Span::addNumber(int number)
{
	if (max_size <= numbers.size())
	{
		throw std::length_error("Cannot add more numbers, span is full");
	}
	numbers.push_back(number);
}

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
	while (begin != end)
	{
		addNumber(*begin);
		++begin;
	}
}

int Span::shortestSpan()
{
	if (numbers.size() < 2)
	{
		throw std::logic_error("Not enough numbers to find a span");
	}

	std::sort(numbers.begin(), numbers.end());

	int min_span = std::numeric_limits<int>::max();
	for (size_t i = 0; i < numbers.size() - 1; ++i)
	{
		int span = numbers[i + 1] - numbers[i];
		if (span < min_span)
		{
			min_span = span;
		}
	}

	return min_span;
}

int Span::longestSpan()
{
	if (numbers.size() < 2)
	{
		throw std::logic_error("Not enough numbers to find a span");
	}

	int min_number = *std::min_element(numbers.begin(), numbers.end());
	int max_number = *std::max_element(numbers.begin(), numbers.end());

	return max_number - min_number;
}
