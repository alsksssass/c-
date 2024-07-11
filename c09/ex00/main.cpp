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
	d.getbase("data.csv");
	d.getinput(input);
	std::string name = "hello | wrodl";
	std::cout << name.find('|') << std::endl;
}