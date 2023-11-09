# include "Dog.hpp"
# include "Cat.hpp"

int main()
{
	const Animal *array[4] = {new Dog(), new Dog(), new Cat(), new Cat()};
	
    for(int i = 0; i < 4; ++i)
    {
		array[i]->makeSound();
		delete array[i];
	}

    return 0;
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q Animal");
}