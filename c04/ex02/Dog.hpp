#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal{
private:
	Brain *brain;
public:
	Dog();
	~Dog();
	Dog(const Dog &a);
	Dog &operator=(const Dog &a);
	virtual void makeSound() const;
	virtual std::string getType() const;
	void giveMemory(int idx, const std::string memory);
	void getMemory(int idx);
};

#endif // DOG_HPP