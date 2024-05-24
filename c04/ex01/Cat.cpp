#include "Cat.hpp"

Cat::Cat() : Animal(){
	std::cout << "Cat Construct Call" << std::endl;
	brain = new Brain;
	type = "Cat";
}
Cat::~Cat(){
	std::cout << "Cat Destruct Call" << std::endl;
	delete brain;
}
Cat::Cat(const Cat &a) {
	std::cout << "Cat Copy Construct Call" << std::endl;
	brain = a.brain;
	type = a.getType();
}
Cat& Cat::operator=(const Cat &a) {
	std::cout << "Cat assignment operator Call" << std::endl;
	if(this != &a)
		brain = a.brain;
	return *this;
}
void Cat::makeSound() const {
	std::cout << "meya ~" << std::endl;
}