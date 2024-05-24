#include "ScavTrap.hpp"

int main()
{
	ClapTrap a("eunbyeul");
	ScavTrap b("sabyun");
	ScavTrap c = b;
	ScavTrap e(b);
	a.attack("sabyun");
	b.attack("eunbyeul");
	b.takeDamage(0);
	b.beRepaired(0);
	b.takeDamage(9);
	b.takeDamage(100);
	b.takeDamage(100);
	b.beRepaired(10);
	b.takeDamage(1);
	c.takeDamage(1);
	c.guardGate();
}