#include "MyString.hpp"
#include "MyFstream.hpp"

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "wrong number of arguments" << std::endl;
		return (1);
	}
	MyFstream infile;
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	infile.open(argv[1], std::ios::in);
	if (infile.fail())
	{
		std::cout << "No such file." << std::endl;
		return (1);
	}
	else
	{
		std::ofstream newfile;
		newfile.open(static_cast<std::string>(argv[1]) + ".replace", std::ios::out);
		if (infile.fail())
		{
			std::cout << "Error opening file." << std::endl;
			return (1);
		}

		infile.replaceFile(newfile, s1, s2);

		infile.close();
		newfile.close();
	}
	return (0);
}