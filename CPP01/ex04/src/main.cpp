#include "MyString.hpp"
#include "MyFstream.hpp"

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "wrong number of arguments" << std::endl;
		return (1);
	}

	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty())
		return (1);

	std::string filename = argv[1];
	MyFstream infile(filename, std::ios::in);
	MyFstream outfile(filename + ".replace", std::ios::out);

	if (infile.is_open() && outfile.is_open())
	{
		infile.replaceWordInFile(outfile, s1, s2);
	}

	/*
	if (infile.openFile(std::ios::in) && outfile.openFile(std::ios::out))
	{
		infile.replaceWordInFile(outfile, s1, s2);
	}
	*/

	return (0);
}