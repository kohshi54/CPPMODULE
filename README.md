# CPPMODULE

## CPP00 ~ Namespaces, classes, member functions, stdio streams, initialization lists, static, const ~

## CPP01 ~ Memory allocation, pointers to members, references, switch statement ~

## CPP02 ~ Ad-hoc polymorphism, operator overloading and Orthodox Canonical class form ~

## CPP03 ~ Inheritance ~
* What is inheritance?\
  Inheritance is a feature of C++, which can use methods and attributes from diffrent class.
  ```
  class Animal()
  {
      public:
        void makeSound();
  }

  class Dog() : public Animal
  {
    public:
      void hitPoll();
  }
  ```
  ```
  {
      Dog a;
      a.makeSound(); // using a method of base class.
  }
  ```
  * Here, makeSound() can be used even though the method is not defined in Dog class, because it derived from Animal class.
  * Note that the access privileges of a derived class can vary based on the access specifier (public, protected, private):
    * If not specified, the access specifier defaults to private.
    * With public inheritance, the derived class inherits methods and attributes with the same access specifiers, except for private methods, which cannot be accessed directly by the derived class.
    * With protected inheritance, the derived class inherits both public and protected methods and attributes as protected. Private methods remain inaccessible to the derived class.
    * With private inheritance, the derived class inherits all methods and attributes as private, and private methods from the base class cannot be accessed directly by the derived class.
   
  * Diamond problem
    Diamond problem can be occurred when a class inherits multiple class with the same base class.\
    ```
    class Dog() : public Animal
    {
      [...]
    }

    class Cat() : public Animal
    {
      [...]
    }

    class DogAndCat() : public Dog, public Cat
    {
      [...]
    }
    ```
    ```
    {
        DogAndCat dc;
    }
    ```
    * Here two Animal object is created??

  * Virtual inheritance
    To avoid diamond problem, virtual inheritance can be used.
    ```
    class Dog() : public virtual Animal // add virtual to avoid diamond inheritance
    {
      [...]
    }

    class Cat() : public virtual Animal // add virtual to avoid diamond  inheritance
    {
      [...]
    }

    class DogAndCat() : public Dog, public Cat
    {
      [...]
    }
    ```
    ```
    {
        DogAndCat dc;
    }
    ```
    * By adding virual, creating ambiguous Animal instance can be avoided.

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
      public:
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
        public:
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
