#include "MyFstream.hpp"
#include "MyString.hpp"

void MyFstream::replaceWordInFile(std::fstream& outfile, std::string s1, std::string s2)
{
	MyString line;

	while (std::getline(*this, line))
	{
		line.replaceLine(line, s1, s2);
		if (this->eof())
			outfile << line << std::flush;
		else
			outfile << line << std::endl;
	}
}

const std::string& MyFstream::getFilename()
{
	return (this->_filename);
}

MyFstream::MyFstream(std::string filename, ios_base::openmode mode) : std::fstream(filename, mode), _filename(filename)
{

}

/*
MyFstream::~MyFstream()
{
	if (this->is_open())
	{
		this->close();
	}
}
*/

/*
bool MyFstream::openFile(ios_base::openmode mode)
{
	this->open(this->getFilename(), mode);
	if (this->fail())
	{
		std::cout << "No such file." << std::endl;
		return (false);
	}
	return (true);
}
*/