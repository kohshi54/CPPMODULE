#if defined(TEST)
# include "WrongDog.hpp"
# include "WrongCat.hpp"
#else
# include "Dog.hpp"
# include "Cat.hpp"
#endif

int main()
{
    #if defined(TEST)
    const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* j = new WrongDog();
    const WrongAnimal* i = new WrongCat();
    #else
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    #endif

    // std::cout << j->getType() << std::endl;
    // std::cout << i->getType() << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
	delete i;
	delete j;
	delete meta;
    return 0;
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q Animal");
}