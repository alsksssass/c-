#include "Zombie.hpp"

int main ()
{
	Zombie one;
	Zombie two("sabyun");
	Zombie *p;

	two.announce();
	p = newZombie("chansu");
	p->announce();
	randomChump("jooh");
	
	delete p;

}
