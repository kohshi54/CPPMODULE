# include "Dog.hpp"
# include "Cat.hpp"

int main()
{
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    // for(;;)
    // {

    // }

    delete j;//should not create a leak
    delete i;

    return 0;
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q Animal");
}