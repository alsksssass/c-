#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <string>
#include <iostream>

#include"ICharacter.hpp"

class AMateria
{
private:
	AMateria();
	AMateria& operator= (AMateria &a);
protected:
	std::string Type;
public:
	AMateria(std::string const & type);
	virtual ~AMateria();
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter &target) =0;
};
#endif // AMATERIA_HPP