#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("eunbyeul");
	ClapTrap b("sabyun");
	ClapTrap c =a;
	ClapTrap e(a);
	a.attack("sabyun");
	b.takeDamage(0);
	b.beRepaired(0);
	b.takeDamage(9);
	b.takeDamage(100);
	b.takeDamage(100);
	b.beRepaired(10);
	b.takeDamage(101);
}