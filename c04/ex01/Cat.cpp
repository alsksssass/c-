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
Cat::Cat(const Cat &a) : Animal(a){
	std::cout << "Cat Copy Construct Call" << std::endl;
	brain = new Brain(*a.brain);
	type = a.getType();
}
Cat& Cat::operator=(const Cat &a) {
	std::cout << "Cat assignment operator Call" << std::endl;
	if(this != &a)
	{
		delete brain;
		brain = new Brain(*a.brain);
		type = a.getType();
	}
	return *this;
}
void Cat::makeSound() const {
	std::cout << "meya ~" << std::endl;
}

void Cat::giveMemory(int idx, const std::string memory){
	brain->setBrain(idx,memory);
}

void Cat::getMemory(int idx){
	std::cout << brain->getBrain(idx) << std::endl;
}