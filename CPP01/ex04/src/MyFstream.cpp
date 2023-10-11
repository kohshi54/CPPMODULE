#include "MyFstream.hpp"
#include "MyString.hpp"

void MyFstream::replaceFile(std::fstream& outfile, std::string s1, std::string s2)
{
	MyString line;

	while (std::getline(*this, line))
	{
		line.replaceLine(line, s1, s2);
		if (this->eof())
			outfile << line;
		else
			outfile << line << std::endl;
	}
}

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

MyFstream::MyFstream(std::string filename) : _filename(filename)
{

}

MyFstream::~MyFstream()
{
	if (this->is_open())
	{
		// std::cout << "closing" << std::endl;
		this->close();
	}
}

const std::string& MyFstream::getFilename()
{
	return (this->_filename);
}