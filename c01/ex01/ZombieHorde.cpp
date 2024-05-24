#include "Zombie.hpp"
Zombie* zombieHorde(int N, std::string name)
{
	if(N<=0)
		return NULL;
	Zombie *ptr = new Zombie [N];

	for (int i = 0; i < N; i++)
		ptr[i].set_name(name);
	return ptr;
}