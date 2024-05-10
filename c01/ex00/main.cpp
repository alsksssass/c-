#include "Zombi.hpp"

int main ()
{
	Zombie one;
	Zombie two("sabyun");
	Zombie *p;

	p = newZombie("chansu");
	randomChump("jooh");
	p->announce();
	
	delete p;

}
