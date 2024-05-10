#include "Zombie.hpp"

int main ()
{
	Zombie one;
	Zombie two("sabyun");
	Zombie *p;

	p = newZombie("chansu");
	two.announce();
	randomChump("jooh");
	p->announce();
	
	delete p;

}
