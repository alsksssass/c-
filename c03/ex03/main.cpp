#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap a;
	DiamondTrap b("sabyun");
	a = DiamondTrap("enbyuel");
	DiamondTrap c(b);
	a.whoAmI();
	a.attack("sabyun");	
	c.takeDamage(9);
	c.takeDamage(9);
	c.takeDamage(89);
	c.takeDamage(1);
	b.whoAmI();
}