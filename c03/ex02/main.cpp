#include "FragTrap.hpp"

int main()
{
	ClapTrap a("eunbyeul");
	FragTrap b("sabyun");
	FragTrap c = b;
	FragTrap e(b);
	a.attack("sabyun");
	b.attack("eunbyeul");
	e.takeDamage(99);
	e.takeDamage(1);
	e.takeDamage(1);
	c.highFivesGuys();
}