#include "MyString.hpp"

void MyString::replace(MyString& line, size_t pos, std::string s1, std::string s2)
{
	size_t len = s1.size();
	line.erase(pos, len);
	line.insert(pos, s2);
}

void MyString::replaceLine(MyString& line, std::string s1, std::string s2)
{
	size_t pos;

	while ((pos = line.find(s1)) != std::string::npos)
	{
		line.replace(line, pos, s1, s2);
	}
}
