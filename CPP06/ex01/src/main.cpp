#include "Serialize.hpp"

int main()
{
	{
		Data* d = new Data;

		d->name = "mike";
		d->age = 22;

		std::cout << "before: name=" << d->age << ", age=" << d->name << std::endl;
		uintptr_t serialized = Serialize::serialize(d);
		// delete d; // here, the memory address allocated before and after reinterpret_cast is same. Therefore deleting the object will create dangling pointer.
		Data* n = Serialize::deserialize(serialized);
		std::cout << "after: name=" << n->age << ", age=" << n->name << std::endl;
	}
	std::cout << "==================" << std::endl;
	{
		Data d;

		d.name = "mike";
		d.age = 22;

		std::cout << "before: name=" << d.age << ", age=" << d.name << std::endl;
		uintptr_t serialized = Serialize::serialize(&d);
		d.name = "bob";
		d.age = 1;
		Data* n = Serialize::deserialize(serialized); // the address pointed at is the same, so the change will affect n as well.
		std::cout << "after: name=" << n->age << ", age=" << n->name << std::endl;
	}

	return 0;
} 
