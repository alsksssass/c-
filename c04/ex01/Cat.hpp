#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
class Cat : public Animal{
private:
	Brain *brain;
public:
	Cat();
	~Cat();
	Cat(const Cat &a);
	Cat &operator=(const Cat &a);
	virtual void makeSound() const;
	void giveMemory(int idx, const std::string memory);
	void getMemory(int idx);
};

#endif // CAT_HPP