#include "Serialize.hpp"

int main()
{
	{
		Data* d = new Data;

		d->name = "mike";
		d->age = 22;

		std::cout << "before: name=" << d->name << ", age=" << d->age << std::endl;
		uintptr_t serialized = Serialize::serialize(d);
		// delete d; // here, the memory address allocated before and after reinterpret_cast is same. Therefore deleting the object will create dangling pointer.
		Data* n = Serialize::deserialize(serialized);
		std::cout << "after: name=" << n->name << ", age=" << n->age << std::endl;
		delete d;
	}
	std::cout << "==================" << std::endl;
	{
		Data d;

		d.name = "mike";
		d.age = 22;

		std::cout << "before: name=" << d.name << ", age=" << d.age << std::endl;
		uintptr_t serialized = Serialize::serialize(&d);
		d.name = "bob";
		d.age = 1;
		Data* n = Serialize::deserialize(serialized); // the address pointed at is the same, so the change will affect n as well.
		std::cout << "after: name=" << n->name << ", age=" << n->age << std::endl;
	}
	return 0;
} 

#ifdef DEBUG
	__attribute__((destructor))
	static void end()
	{
		system("leaks -q serialize");
	}
#endif
