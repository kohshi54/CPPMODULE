# include "Dog.hpp"
# include "Cat.hpp"

int main()
{
	const Animal *array[4] = {new Dog(), new Dog(), new Cat(), new Cat()};

	Animal test;
	Animal test2;

	std::cout << test.getType() << std::endl;
	std::cout << test2.getType() << std::endl;

	test2 = test;

	std::cout << test.getType() << std::endl;
	std::cout << test2.getType() << std::endl;
	
    for(int i = 0; i < 4; ++i)
    {
		array[i]->makeSound();
		delete array[i];
	}

    return 0;
}

#ifdef DEBUG
__attribute__((destructor))
static void destructor() {
    system("leaks -q Animal");
}
#endif