#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : virtual public Animal{
public:
	Dog();
	~Dog();
	Dog(const Dog &a);
	Dog &operator=(const Dog &a);
	virtual void makeSound() const;
};

#endif // DOG_HPP