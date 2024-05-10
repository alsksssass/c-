#include "Harl.hpp"
#include <iostream>
void Harl::debug(void){
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. \nI really do!\n" << std::endl;
}
void Harl::info(void){
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. \nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" <<std::endl;
}
void Harl::warning(void){
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}
void Harl::error(void){
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string cmp_case[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int ret = 9;
	for (int i = 0; i < (int)cmp_case->size(); i++)
	{
		int result = (int)cmp_case[i].compare(level);
		if (result == 0)
		{
			ret = i;
			break;
		}
	}
	switch (ret)
	{
	case 0:
		debug();
		 __attribute__((fallthrough));
	case 1:
		info();
		 __attribute__((fallthrough));
	case 2:
		warning();
		 __attribute__((fallthrough));
	case 3:
		error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}