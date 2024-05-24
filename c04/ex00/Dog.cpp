#include "Dog.hpp"

Dog::Dog() : Animal(){
	std::cout << "Dog Construct Call" << std::endl;
	type = "Dog";
}
Dog::~Dog(){
	std::cout << "Dog Destruct Call" << std::endl;
}
Dog::Dog(const Dog &a){
	std::cout << "Dog Copy Construct Call" << std::endl;
	type = a.getType();
}
Dog& Dog::operator=(const Dog &) {
	std::cout << "Dog assignment operator Call" << std::endl;
	return *this;	
}
void Dog::makeSound() const {
	std::cout << "bark !" << std::endl;
}