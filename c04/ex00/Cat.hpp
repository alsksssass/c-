#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : virtual public Animal{
public:
	Cat();
	~Cat();
	Cat(const Cat &a);
	Cat &operator=(const Cat &a);
	virtual void makeSound() const;
};

#endif // CAT_HPP