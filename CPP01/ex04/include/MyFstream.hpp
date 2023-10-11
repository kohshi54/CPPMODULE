#ifndef __MY_FSTREAM_HPP
# define __MY_FSTREAM_HPP

#include <fstream>
#include <iostream>

class MyFstream : public std::ifstream
{
	public:
		void replaceFile(std::ofstream& outfile, std::string s1, std::string s2);
};

#endif