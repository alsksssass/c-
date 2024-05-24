#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {}
WrongAnimal::~WrongAnimal(){}
WrongAnimal::WrongAnimal(const WrongAnimal &a): type(a.type) {}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &a){
	if(this != &a)
		type = a.type;
	return *this;
}
std::string WrongAnimal::getType() const{
	return type;
}
void WrongAnimal::makeSound() const{
	std::cout << "WrongAnimal's dosn't have sound" << std::endl;
}