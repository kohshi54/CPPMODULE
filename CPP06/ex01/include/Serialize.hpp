#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>

typedef struct Data
{
	std::string name;
	int age;
}	Data;

class Serialize
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:
		Serialize();
};

#endif
