# CPPMODULE

## CPP00 ~ Namespaces, classes, member functions, stdio streams, initialization lists, static, const ~
* What is namespaces?\
  A namespace is a scope for identifiers, used to prevent collisions of types, function names, and variable names from different libraries or files. It allows for the same name to be used in different contexts without confusion.

* What is class?\
  A class in is a type that groups functions and attributes to represent and manipulate data as a single entity.

* What is member functions?\
  A member function, a method, is defined within a class to operate on instances of that class, manipulating the object's data or providing functionality.

* What is stdio streams?\
  In C++, stream objects are used for input and output operations. The standard input/output streams, such as cin for standard input and cout for standard output, are used to read from the keyboard and write to the console, respectively. File streams, like ifstream and ofstream, are used for file operations. Thus, in C++, I/O operations are commonly performed using stream abstractions.

* What is initialization lists?\
  An initialization list is a feature in C++ that allows member attributes to be initialized directly within a constructor's declaration. Const member can be initialize using this feature.
  ```
  Animal::Animal(const string &type) : _type(type), _brain("") // initialization lists.
  {
      [...]
  }
  ```
  * Here, member attribute _type is initialized with the passed argument 'type', and _brain with an empty string.

* What is static?
  Static is an identifier for functions and attributes, to contain only one instance. If a class attribute is speciefied as static, the object will be created only once and shared within multiple instances.

## CPP01 ~ Memory allocation, pointers to members, references, switch statement ~

## CPP02 ~ Ad-hoc polymorphism, operator overloading, Orthodox Canonical class form ~
* What is ad-hoc polymorphism?\
  Ad-hoc polymorphism allows functions with the same name to be applied to different types of input, typically through operator or function overloading.

* What is operator overloading?\
  Operator overloading is a feature in C++, which provides a more intuitive interface for custom classes, and it can be implemented as a member function of the class.
  For example, C++ does not provide native Fixed class, but can be implemented using operator overloading as below.
  ```
  class Fixed
  {
    public:
      [...]
      Fixed operator+(const Fixed& rhs) const;

    private:
      int _rawBits;
      static const int _fractBits = 8;
  };

  Fixed Fixed::operator+(const Fixed& rhs) const
  {
      Fixed result;
      result.setRawBits(this->getRawBits() + rhs.getRawBits());
      return (result);
  }
  ```
  ```
  {
      Fixed a;
      Fixed b;
      a + b
  }
  ```
  * Here, a + b can be done by operator overloading of + operator.

* What is Orthodox Canonical form?\
  The Orthodox Canonical Form in C++98 is a pattern where the compiler automatically provides default implementations for the following four special member functions when they are not explicitly defined by the user:
  ```
  class Animal()
  {
      Animal();                                // Constructor
      Animal(const Animal &other);             // Copy constructor
      Animal &operator=(const Animal &rhs);    // Copy assignment operator
      ~Animal();                               // Destructor
  };
  ```
## CPP03 ~ Inheritance ~
* What is inheritance?\
  Inheritance is a feature of C++, which can use methods and attributes from diffrent class.
  ```
  class Animal
  {
      public:
        void makeSound();
  };

  class Dog : public Animal
  {
    public:
      void hitPoll();
  };
  ```
  ```
  {
      Dog a;
      a.makeSound(); // using a method of base class.
  }
  ```
  * Here, makeSound() can be used even though the method is not defined in Dog class, because it derived from Animal class.
  * Note that the access privileges of a derived class can be limited by the access specifier (public, protected, private):
    * If not specified, the access specifier defaults to private.
    * With public inheritance, the derived class inherits methods and attributes with the same access specifiers, except for private methods, which cannot be accessed directly by the derived class.
    * With protected inheritance, the derived class inherits both public and protected methods and attributes as protected. Private methods remain inaccessible to the derived class.
    * With private inheritance, the derived class inherits all methods and attributes as private, and private methods from the base class cannot be accessed directly by the derived class.
   
* Diamond problem and virtual inheritance\
    The diamond problem occurs when a class inherits from multiple classes that share the same base class. This leads to the creation of multiple copies of the base class's attributes and methods in the derived class, resulting in ambiguity. To prevent the diamond problem, virtual inheritance can be used, which ensures that only one copy of the base class's attributes and methods is inherited, thereby eliminating ambiguity.
    ```
    class Dog : public virtual Animal // add virtual to avoid diamond inheritance
    {
      [...]
    };

    class Cat : public virtual Animal // add virtual to avoid diamond  inheritance
    {
      [...]
    };

    class DogAndCat : public Dog, public Cat
    {
      [...]
    };
    ```
    ```
    {
        DogAndCat dc;
    }
    ```
    * By adding 'virtual', only one set of 'Animal' methods and attributes will be created, which avoids the creation of an ambiguous 'Animal' instance.

## CPP04 ~ Subtype polymorphism, abstract classes, interfaces ~
* What is subtype polymorphism?\
  Subtype polymorphism is a feature of inheritance where a derived class, which originates from a base class, is recognized as an instance of the base class while retaining its own derived methods and attributes. This provides a uniform interface for functions that vary in implementation depending on the types involved.
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
  class AAnimal
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
    class IAnimal
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


## Unresolved issues
* For copy constructor implementation, should i copy attributes directly or use copy assignment operator?
  ```
  Animal::Animal(const Animal &other)
  {      
      *this = other
  }
  // or
  Animal::Animal(const Animal &other)
  {
    this->_type = rhs._type;
  }

  Animal &Animal::operator=(const Animal &rhs)
  {
      this->_type = rhs._type;
  }
  
  ```
  * Of courese, using initializer list is clearly different but for the above two, which should it be used?

* What is object exactly? Is it diffrent from instance?
