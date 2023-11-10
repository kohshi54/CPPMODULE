# CPPMODULE

## CPP04 ~ Subtype polymorphism, abstract classes, interfaces ~
* What is polymorphism?\
  Polymorphism is object behaves as it is.
  ```
  // Dog/Cat class inherits Animal class which has a method makeSound().
  Animal *Animal a = new Dog();
  a.makeSound(); // will output the sound of dog.

  Animal *Animal b = new Cat();
  b.makeSound(); // will output the sound of cat.
  ```
  * Here it is interesting that a and b are makeing a different sound even though they use the same makeSound() which is the method of Animal class.

* What is abstract class?\
  Abstract class is a class which has at least one virtual function.
  ```
  class AAnimal()
  {
      virtual void makeSound() = 0;
  };
  ```
  
