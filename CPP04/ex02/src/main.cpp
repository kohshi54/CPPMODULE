# include "Dog.hpp"
# include "Cat.hpp"

int main()
{
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
#ifdef ERROR
	AAnimal *willfail = new AAnimal(); // compile error, since abstract class cannot be instantiated.
#endif

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