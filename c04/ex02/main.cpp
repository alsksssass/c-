#include "Dog.hpp"
#include "Cat.hpp"
// void a(){system("leaks a.out");}
int main()
{
	//Animal arr;
	Cat *arr1 [5];
	Dog *arr2 [5];
	for(int i = 0; i < 5; i++)
	{
			arr1[i] = new Cat();
			arr2[i] = new Dog();
	}
	for(int i = 0; i < 5; i++)
	{
		std::cout << arr1[i]->getType() << std::endl;
		arr1[i]->makeSound();
		std::cout << arr2[i]->getType() << std::endl;
		arr2[i]->makeSound();
	}
	for(int i = 0; i < 5; i++)
	{
		delete arr1[i];
		delete arr2[i];
	}
	// std::atexit(a);
	return 0;
}