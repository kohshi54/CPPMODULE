#include <fstream>
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "wrong number of arguments" << std::endl;
		return (1);
	}
	std::ifstream infile;
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

		std::string line;
		size_t pos;
		size_t len = s1.size();
        while (std::getline(infile, line))
		{
			while ((pos = line.find(s1)) != std::string::npos)
			{
				// line.replace(pos, len, s2);
				line.erase(pos, len);
				line.insert(pos, s2);
			}
			if (infile.eof())
				newfile << line;
			else
				newfile << line << std::endl;
        }

		infile.close();
		newfile.close();
	}
	return (0);
}