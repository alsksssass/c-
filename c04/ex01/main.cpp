#include "Dog.hpp"
#include "Cat.hpp"
// void aa(){system("leaks a.out");}
int main()
{
	Animal *arr [10];
	for(int i = 0; i < 10; i++)
	{
		if(i%2 == 0)
			arr[i] = new Cat();
		else
			arr[i] = new Dog();
	}
	for(int i = 0; i < 10; i++)
		arr[i]->makeSound();
	for(int i = 0; i < 10; i++)
		delete arr[i];
	Cat *a = new Cat();
	a->giveMemory(0,"Hello_world!");
	a->giveMemory(1,"sabyun!");
	a->getMemory(0);
	a->getMemory(1);
	Cat b;
	b = *a;

	delete a;
	b.getMemory(0);
	b.getMemory(1);
	b.getMemory(2);
	b.getMemory(-1);
	// std::atexit(aa);
	return 0;
}