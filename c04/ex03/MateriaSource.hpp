#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

class MateriaSource : public IMateriaSource {
private:
	AMateria *memory[4];
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource &a);
	MateriaSource &operator=(const MateriaSource &a);
	virtual void learnMateria(AMateria* a);
	virtual AMateria* createMateria(std::string const & type);
};

#endif // MATERIASOURCE_HPP