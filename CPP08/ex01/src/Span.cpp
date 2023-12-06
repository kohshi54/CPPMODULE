#include "Span.hpp"

Span::Span() : max_size(0)
{
#ifdef DEBUG
	std::cout << "Span default constructor called" << std::endl;
#endif
}

Span::Span(unsigned int N) : max_size(N)
{
#ifdef DEBUG
	std::cout << "Span parameterized constructor called" << std::endl;
#endif
}

Span::Span(const Span& other) : numbers(other.numbers), max_size(other.max_size)
{
#ifdef DEBUG
	std::cout << "Span copy constructor called" << std::endl;
#endif
}

Span& Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
#ifdef DEBUG
	std::cout << "Span copy assignment operator called" << std::endl;
#endif
		this->numbers = rhs.numbers;
		this->max_size = rhs.max_size;
	}
	return *this;
}

Span::~Span()
{
#ifdef DEBUG
	std::cout << "Span destructor called" << std::endl;
#endif
}

void Span::addNumber(int number)
{
	if (max_size <= numbers.size())
	{
		throw std::length_error("Cannot add more numbers, span is full");
	}
	numbers.push_back(number);
}

unsigned int Span::shortestSpan()
{
	if (numbers.size() < 2)
	{
		throw std::logic_error("Not enough numbers to find a span");
	}

	std::sort(numbers.begin(), numbers.end());

	unsigned int min_span = std::numeric_limits<unsigned int>::max();
	for (size_t i = 0; i < numbers.size() - 1; ++i)
	{
		unsigned int span = std::abs(static_cast<long>(numbers[i + 1]) - static_cast<long>(numbers[i]));
		if (span < min_span)
		{
			min_span = span;
		}
	}

	return min_span;
}

unsigned int Span::longestSpan()
{
	if (numbers.size() < 2)
	{
		throw std::logic_error("Not enough numbers to find a span");
	}

	int min_number = *std::min_element(numbers.begin(), numbers.end());
	int max_number = *std::max_element(numbers.begin(), numbers.end());

	return static_cast<long>(max_number) - static_cast<long>(min_number);
}
