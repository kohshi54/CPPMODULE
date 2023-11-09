# include "Dog.hpp"
# include "Cat.hpp"

int main()
{
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    // AAnimal *willfail = new AAnimal();

	j->makeSound();
	i->makeSound();

    delete j;
    delete i;

    return 0;
}

#ifdef DEBUG
__attribute__((destructor))
static void destructor() {
    system("leaks -q Animal");
}
#endif