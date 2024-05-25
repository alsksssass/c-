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
Dog::Dog(const Dog &a) : Animal(a){
	std::cout << "Dog Copy Construct Call" << std::endl;
	brain = new Brain(*a.brain);
	type = a.getType();
}
Dog& Dog::operator=(const Dog &a) {
	std::cout << "Dog assignment operator Call" << std::endl;
	if(this != &a)
	{
		delete brain;
		brain = new Brain(*a.brain);
		type = a.getType();
	}
	return *this;
}
void Dog::makeSound() const {
	std::cout << "bark !" << std::endl;
}
void Dog::giveMemory(int idx, const std::string memory){
	brain->setBrain(idx,memory);
}

void Dog::getMemory(int idx){
	std::cout << brain->getBrain(idx) << std::endl;
}

std::string Dog::getType() const {
	return type;
}