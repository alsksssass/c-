#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	type = "WrongCat";
}
WrongCat::~WrongCat(){}
WrongCat::WrongCat(const WrongCat &a) {
	type = a.getType();
}
WrongCat& WrongCat::operator=(const WrongCat &) {
	return *this;
}
void WrongCat::makeSound() const {
	std::cout << "Wrong meya ~" << std::endl;
}