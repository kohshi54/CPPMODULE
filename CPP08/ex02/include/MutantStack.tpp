#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
#ifdef DEBUG
	std::cout << "MutantStack defualt constructor called" << std::endl;
#endif
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other)
{
#ifdef DEBUG
	std::cout << "MutantStack copy constructor called" << std::endl;
#endif
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &rhs)
{
	/* Todo: check if the lhs and rhs are identical to avoid self assign */
#ifdef DEBUG
	std::cout << "MutantStack copy assignment operator called" << std::endl;
#endif
	std::stack<T>::operator=(rhs);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
#ifdef DEBUG
	std::cout << "MutantStack destructor called" << std::endl;
#endif
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return this->c.end();
}
