#include "Zombie.hpp"
#include <iostream>
int main()
{
	Zombie *ptr;

	ptr = zombieHorde(5, "sabyun");
	if (ptr)
	{
		ptr[2].announce();
		ptr[3].announce();
		delete[] ptr;
	}
	return 0;
}