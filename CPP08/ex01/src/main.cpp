#include <iostream>
#include <vector>
#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "===============" << std::endl;
	{
		Span mySpan(10000);
		std::vector<int> testNumbers(10000);

		std::srand(static_cast<unsigned int>(std::time(NULL)));

		for (size_t i = 0; i < testNumbers.size(); ++i)
		{
			testNumbers[i] = std::rand();
		}

		mySpan.addNumbers(testNumbers.begin(), testNumbers.end());
		try
		{
			std::cout << "Shortest Span: " << mySpan.shortestSpan() << std::endl;
			std::cout << "Longest Span: " << mySpan.longestSpan() << std::endl;
		} catch (const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	return 0;
}

#ifdef DEBUG
	__attribute__((destructor))
	static void end()
	{
		system("leaks -q span");
	}
#endif
