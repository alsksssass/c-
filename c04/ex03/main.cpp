#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
// void a (){system("leaks a.out");}
int main()
{
	// std::atexit(a);
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter *me = new Character("me");
	ICharacter *bob = new Character("bob");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->use(0, *bob);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->use(1, *bob);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(0);

	delete bob;
	delete me;
	delete src;
	return 0;
}