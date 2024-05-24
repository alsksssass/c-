#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria{
public:
	Cure();
	~Cure();
	Cure(const Cure &a);
	Cure &operator=(const Cure &a);
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif // CURE_HPP