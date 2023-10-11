#ifndef __MY_FSTREAM_HPP
# define __MY_FSTREAM_HPP

#include <fstream>
#include <iostream>

class MyFstream : public std::fstream
{
	public:
		void replaceFile(std::fstream& outfile, std::string s1, std::string s2);
		bool openFile(std::string filename, ios_base::openmode mode);
		~MyFstream();
};

#endif