#include "AMateria.hpp"
AMateria::AMateria() : Type("type"){}
AMateria::AMateria(std::string const & type){
	std::cout << "AMateria Copy Construct Call" << std::endl;
	Type = type;
}
AMateria::~AMateria(){}
AMateria& AMateria::operator= (AMateria &a){
	if(this == &a) return *this;
	Type = a.getType();
	return *this;
}
std::string const & AMateria::getType() const{
	return Type;
}