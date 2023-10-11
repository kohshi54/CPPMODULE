#ifndef __MY_FSTREAM_HPP
# define __MY_FSTREAM_HPP

#include <fstream>
#include <iostream>

class MyFstream : public std::fstream
{
	public:
		void replaceFile(std::fstream& outfile, std::string s1, std::string s2);
		bool openFile(ios_base::openmode mode);
		MyFstream(std::string filename);
		~MyFstream();
		const std::string& getFilename();

	private:
		std::string _filename;
};

#endif