# include "Dog.hpp"
# include "Cat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

	Animal *array[4] = {new Dog(), new Dog(), new Cat(), new Cat()};
	
    for(int i = 0; i < 4; ++i)
    {
		delete array[i];
	}
	// j->makeSound();
	// i->makeSound();

	Dog basic;
	{
		Dog tmp = basic;
	}

    delete j;
    delete i;

    return 0;
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q Animal");
}