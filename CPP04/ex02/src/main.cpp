# include "Dog.hpp"
# include "Cat.hpp"

int main()
{
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    // AAnimal *willfail = new AAnimal();

    delete j;
    delete i;

    return 0;
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q Animal");
}