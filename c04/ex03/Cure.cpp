#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure Construct Call" << std::endl;
}
Cure::~Cure() {
	std::cout << "Cure Destruct Call" << std::endl;
}
Cure::Cure(const Cure &a) : AMateria(a.getType()){
	std::cout << "Cure Copy Construct Call" << std::endl;
}
Cure& Cure::operator=(const Cure &){
	std::cout << "Cure assignment operator Call" << std::endl;
	return *this;
}
AMateria* Cure::clone() const{
	AMateria *a = new Cure();
	return a;
}
void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "’s wounds * "<< std::endl;
}