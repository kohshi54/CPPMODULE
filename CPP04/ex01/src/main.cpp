# include "Dog.hpp"
# include "Cat.hpp"

int main()
{
	{
		const Animal *array[4] = {new Dog(), new Dog(), new Cat(), new Cat()};
		
		for(int i = 0; i < 4; ++i)
		{
			array[i]->makeSound();
			delete array[i];
		}
	}

	std::cout << "======================" << std::endl;

	{
		Animal test;
		Dog test2;

		std::cout << test.getType() << ":" << &(test.getType()) << std::endl;
		std::cout << test2.getType() << ":" << &(test2.getType()) << std::endl;

		test = test2;

		std::cout << test.getType() << ":" << &(test.getType()) << std::endl;
		std::cout << test2.getType() << ":" << &(test2.getType()) << std::endl;
	}

	std::cout << "======================" << std::endl;

	{
		Dog t1;
		Dog t2;

		// std::cout << "t1:" << t1.getBrain() << std::endl;
		// std::cout << "t2:" << t2.getBrain() << std::endl;

		t1 = t2;

		std::cout << "t1:" << t1.getBrain() << std::endl;
		std::cout << "t2:" << t2.getBrain() << std::endl;
	}

    return 0;
}

#ifdef DEBUG
__attribute__((destructor))
static void destructor() {
    system("leaks -q Animal");
}
#endif