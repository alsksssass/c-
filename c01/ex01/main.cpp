#include "Zombi.hpp"
#include <iostream>
int main()
{
	Zombie *ptr;

	ptr = zombieHorde(10,"sabyun");

	ptr[2].announce();
	ptr[3].announce();
	delete [] ptr;
	return 0;
}