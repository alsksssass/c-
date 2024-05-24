#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal{
public:
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat &a);
	WrongCat &operator=(const WrongCat &a);
	void makeSound() const;
};

#endif // WRONGCAT_HPP