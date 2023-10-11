#ifndef __MYSTRING_HPP___
# define __MYSTRING_HPP___

#include <fstream>
#include <iostream>

class MyString : public std::string
{
	public:
		void replace(MyString& line, size_t pos, std::string s1, std::string s2);
		void replaceLine(MyString& line, std::string s1, std::string s2);
};

#endif