#include "MyString.hpp"
#include "MyFstream.hpp"

int main(int argc, char *argv[])
{
	MyFstream infile;
	MyFstream newfile;
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (argc != 4)
	{
		std::cerr << "wrong number of arguments" << std::endl;
		return (1);
	}

	if (infile.openFile(filename, std::ios::in))
	{
		if (newfile.openFile(filename + ".replace", std::ios::out))
		{
			infile.replaceFile(newfile, s1, s2);
			newfile.close();
		}
		infile.close();
	}

	// if (infile.openFile(argv[1], std::ios::in) == false)
	// 	return (1);
	// else
	// {		
	// 	if (newfile.openFile(static_cast<std::string>(argv[1]) + ".replace", std::ios::out) == false)
	// 	{
	// 		infile.close();
	// 		return (1);
	// 	}
	// 	infile.replaceFile(newfile, s1, s2);
	// 	infile.close();
	// 	newfile.close();
	// }
	return (0);
}