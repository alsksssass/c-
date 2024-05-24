#include "Cat.hpp"

Cat::Cat() : Animal(){
	std::cout << "Cat Construct Call" << std::endl;
	type = "Cat";
}
Cat::~Cat(){
	std::cout << "Cat Destruct Call" << std::endl;
}
Cat::Cat(const Cat &a) {
	std::cout << "Cat Copy Construct Call" << std::endl;
	type = a.getType();
}
Cat& Cat::operator=(const Cat &) {
	std::cout << "Cat assignment operator Call" << std::endl;
	return *this;
}
void Cat::makeSound() const {
	std::cout << "meya ~" << std::endl;
}