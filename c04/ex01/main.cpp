#include "Dog.hpp"
#include "Cat.hpp"
//void a(){system("leaks a.out");}
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

	//std::atexit(a);
	return 0;
}