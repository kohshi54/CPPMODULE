#ifndef __MY_FSTREAM_HPP__
# define __MY_FSTREAM_HPP__

#include <fstream>
#include <iostream>

class MyFstream : public std::fstream
{
	public:
		MyFstream(std::string filename, ios_base::openmode mode);
		// ~MyFstream();
		// bool openFile(ios_base::openmode mode);
		const std::string& getFilename();
		void replaceWordInFile(std::fstream& outfile, std::string s1, std::string s2);

	private:
		std::string _filename;
};

#endif