#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include "Color.hpp"

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& rhs);
		const T& operator[](unsigned int index) const;
		T& operator[](unsigned int index);
		~Array();

		unsigned int size() const;

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		T* _array;
		unsigned int _size;

};

// template <typename T>
// std::ostream& operator<<(std::ostream& os, const Array<T>& array);

#include "Array.tpp"

#endif
