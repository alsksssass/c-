#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter{
private:
	std::string Name;
	AMateria *Inventory[4];
	int idx[4];
public:
	Character();
	Character(std::string name);
	~Character();
	Character(const Character &a);
	Character &operator=(const Character &a);
	virtual std::string const &getName() const;
	virtual void equip(AMateria *m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter &target);
};

#endif // CHARACTER_HPP