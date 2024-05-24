#include "Animal.hpp"
Animal::Animal() : type("Animal") {
	std::cout << "Animal Construct Call" << std::endl;
}
Animal::~Animal(){
	std::cout << "Animal Destruct Call" << std::endl;
}
Animal::Animal(const Animal &a): type(a.type) {
	std::cout << "Animal Copy Construct Call" << std::endl;
}
Animal& Animal::operator=(const Animal &a){
	std::cout << "Animal assignment operator Call" << std::endl;
	if(this != &a)
		type = a.type;
	return *this;
}
std::string Animal::getType() const{
	return type;
}
void Animal::makeSound() const{
	std::cout << "Animal's dosn't have sound" << std::endl;
}