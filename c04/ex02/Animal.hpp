#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
#include <iostream>
class Animal {
protected:
	std::string type;
public:
	Animal();
	virtual ~Animal();
	Animal(const Animal &a);
	Animal &operator=(const Animal &a);
	virtual std::string getType() const =0;
	virtual void makeSound() const =0 ;
};

#endif // ANIMAL_HPP