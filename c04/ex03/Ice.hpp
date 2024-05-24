#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria{
public:
	Ice();
	~Ice();
	Ice(const Ice &a);
	Ice &operator=(const Ice &a);
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif // ICE_HPP