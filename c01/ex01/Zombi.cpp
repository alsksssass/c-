#include "Zombi.hpp"
#include <iostream>

Zombie::Zombie(){
	this->name = "name";
	announce();
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}
Zombie::~Zombie(){
	std::cout << this->name << ": " << " died." << std::endl;
}

void Zombie::announce()
{
	std::cout << name << ": " <<"BraiiiiiiinnnzzzZ..." << std::endl;
}
void Zombie::set_name(std::string name){
	this->name = name;
}