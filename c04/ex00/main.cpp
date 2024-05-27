#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	const WrongAnimal *test = new WrongAnimal();
	const WrongAnimal *cat = new WrongCat();
	const WrongCat *cat2 = new WrongCat();
	test->makeSound();
	cat->makeSound();
	cat2->makeSound();
	delete cat2;
	delete test;
	delete cat;
	return 0;
}