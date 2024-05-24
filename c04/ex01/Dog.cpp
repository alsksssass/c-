#include "Dog.hpp"

Dog::Dog() : Animal(){
	std::cout << "Dog Construct Call" << std::endl;
	brain = new Brain;
	type = "Dog";
}
Dog::~Dog(){
	std::cout << "Dog Destruct Call" << std::endl;
	delete brain;
}
Dog::Dog(const Dog &a){
	std::cout << "Dog Copy Construct Call" << std::endl;
	brain = a.brain;
	type = a.getType();
}
Dog& Dog::operator=(const Dog &a) {
	std::cout << "Dog assignment operator Call" << std::endl;
	if(this != &a)
		brain = a.brain;
	return *this;	
}
void Dog::makeSound() const {
	std::cout << "bark !" << std::endl;
}