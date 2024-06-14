#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

// void a()
// {system("leaks a.out");}
Base *generate(void)
{
	Base *ret = 0;
	std::srand(std::time(0) + std::rand());
	int i = std::rand() % 3;
	switch (i)
	{
	case 0:
		ret = new A();
		break;
	case 1:
		ret = new B();
		break;
	case 2:
		ret = new C();
	}
	return ret;
};
void identify(Base *p)
{
	A *a_check = dynamic_cast<A *>(p);
	if (a_check != NULL)
	{
		std::cout << "A type" << std::endl;
		return;
	}
	B *b_check = dynamic_cast<B *>(p);
	if (b_check != NULL)
	{
		std::cout << "B type" << std::endl;
		return;
	}
	C *c_check = dynamic_cast<C *>(p);
	if (c_check != NULL)
	{
		std::cout << "C type" << std::endl;
		return;
	}
}
void identify(Base &p)
{
	try
	{
		A &a_check = dynamic_cast<A &>(p);
		(void)a_check;
	}
	catch (std::exception &exp)
	{
		try
		{
			B &b_check = dynamic_cast<B &>(p);
			(void)b_check;
		}
		catch (std::exception &exp)
		{
			try
			{
				C &c_check = dynamic_cast<C &>(p);
				(void)c_check;
			}
			catch (std::exception &exp)
			{
				return;
			}
			std::cout << "C type" << std::endl;
			return;
		}
		std::cout << "B type" << std::endl;
		return;
	}
	std::cout << "A type" << std::endl;
}
int main()
{
	// atexit(a);
	for(int i = 0; i < 10; i++)
	{
	Base * temp = generate();
	identify(temp);
	identify(*temp);
	std::cout << std::endl;
	delete temp;
	}
}