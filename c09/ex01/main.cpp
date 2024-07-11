#include "RPN.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
		return 0;
	RPN a;

	std::string in = argv[1];
	try
	{
		a.push(in);
	}
	catch(std::exception &a)
	{
		std::cout << a.what() << std::endl;
	}
};