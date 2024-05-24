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
	std::string getType() const;
	virtual void makeSound() const;
};

#endif // ANIMAL_HPP