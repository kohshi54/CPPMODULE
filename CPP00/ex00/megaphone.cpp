#include "megaphone.hpp"

void	toUpperCase(std::string& input) {
    for (size_t i = 0; i < input.size(); ++i)
	{
        input[i] = std::toupper(static_cast<unsigned char>(input[i]));
    }
}

#ifndef TEST
int	main(int argc, char *argv[])
{
    if (argc < 2)
	{
        std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
	for (int i = 1; i < argc; ++i)
	{
	    std::string inputString = argv[i];
		toUpperCase(inputString);
		std::cout << inputString;
	}
	std::cout << std::endl;
    return (0);
}
#endif