#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice Construct Call" << std::endl;
}
Ice::~Ice() {
	std::cout << "Ice Destruct Call" << std::endl;
}
Ice::Ice(const Ice &a) : AMateria(a.getType()){
	std::cout << "Ice Copy Construct Call" << std::endl;
}
Ice& Ice::operator=(const Ice &){
	std::cout << "Ice assignment operator Call" << std::endl;
	return *this;
}
AMateria* Ice::clone() const{
	AMateria *a = new Ice();
	return a;
}
void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}