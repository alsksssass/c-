#include "BitcoinExchange.hpp"
int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 0;
	}
	std::string input = argv[1];
	BitcoinExchange d;
	try{
	d.getbase("data.csv");
	d.getinput(input);
	}
	catch(std::exception &e)
	{
		std::cout << "error : " << e.what() << std::endl;
	}
}