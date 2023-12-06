#include "Span.hpp"

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
	while (begin != end)
	{
		addNumber(*begin);
		++begin;
	}
}
