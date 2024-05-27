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
	Cat *c = new Cat(*a);
	Cat b;
	b = *a;

	delete a;
	c->getMemory(0);
	b.getMemory(0);
	b.getMemory(1);
	b.getMemory(2);
	b.getMemory(-1);
	delete c;
	// std::atexit(aa);
	return 0;
}