#include "MyFstream.hpp"
#include "MyString.hpp"

void MyFstream::replaceFile(std::ofstream& outfile, std::string s1, std::string s2)
{
	MyString line;

	while (std::getline(*this, line))
	{
		line.replaceLine(line, s1, s2);
		if (this->eof())
			outfile << line;
		else
			outfile << line << std::endl;
	}
}