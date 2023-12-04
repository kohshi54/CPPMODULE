#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
#ifdef DEBUG
	std::cout << GREEN << "Array constructor called" << RESET << std::endl;
#endif
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
#ifdef DEBUG
	std::cout << GREEN << "Array copy constructor called" << RESET << std::endl;
#endif
}
template <typename T>
Array<T>::Array(const Array& other) : _array(new T[other._size]), _size(other._size)
{
#ifdef DEBUG
	std::cout << GREEN << "Array parameterized constructor called" << RESET << std::endl;
#endif
	for (unsigned int i = 0; i < other._size; ++i)
	{
		this->_array[i] = other._array[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
{
	if (this != &rhs)
	{
#ifdef DEBUG
	std::cout << YELLOW << "Array copy assignment operator called" << RESET << std::endl;
#endif
		T* newArray = new T[rhs._size];
		for (unsigned int i = 0; i < rhs._size; ++i)
		{
			newArray[i] = rhs._array[i];
		}
		delete[] this->_array;
		this->_array = newArray;
		this->_size = rhs._size;
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
#ifdef DEBUG
	std::cout << RED << "Array destructor called" << RESET << std::endl;
#endif	
	delete[] this->_array;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return this->_size;
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (this->_size <= index)
		throw OutOfBoundsException();
	return this->_array[index];
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (this->_size <= index)
		throw OutOfBoundsException();
	return this->_array[index];
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return "index out of bounds";
}
