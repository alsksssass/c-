#include "AMateria.hpp"
AMateria::AMateria(std::string const & type){
	std::cout << "AMateria Copy Construct Call" << std::endl;
	Type = type;
}
AMateria::~AMateria(){}
std::string const & AMateria::getType() const{
	return Type;
}