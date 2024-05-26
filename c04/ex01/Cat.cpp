#ifndef CAT_HPP
#define CAT_HPP

class Cat {
public:
	Cat();
	~Cat();
	Cat(const Cat &a);
	Cat &operator=(const Cat &a);
};

#endif // CAT_HPP

#include "Cat.hpp"

Cat::Cat()
Cat::~Cat()
Cat::Cat(const Cat &a)
Cat& Cat::operator=(const Cat &a)