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
  Abstract class is a class which has at least one pure virtual function and cannnot be instantiated.
  ```
  class AAnimal()
  {
      virtual void makeSound() = 0; // pure virtual function.
  };
  ```
  * Pure virtual function is a function which is intended to be implemented in derived class, so the acutual implementation is not done in base class.
  * Note that virtual function, not a pure virtual function can be implemented in base class, but it will be override in derived class if implemented in derived class as well.

* What is interface?\
    Interface is a class that does not have any implementation of method and the attribute. Although C++ does not have interface feature officially, near feature can be implented by making all class method pure virtual function.
    ```
    class IAnimal()
    {
        virtual ~IAnimal() {}
        virtual void makeDound() = 0;
        virtual void move() = 0;
    };
    ```
    * By setting virtual to destructor, the appropriate destructor is called, even the acutal object is derived class as below.
      ```
      {
          Animal *a = new Dog();
          delete a;
      }
      ```
      * Here, the destructor of the Dog class should be called. If the derived class (Dog class) contains features that are additional to those in the Animal class, it may lead to undesirable behavior such as memory leaks.
