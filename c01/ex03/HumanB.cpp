#include "HumanB.hpp"
#include <iostream>
HumanB::HumanB(){
	this->name = "NONE";
	weapon = NULL;
}
HumanB::HumanB(std::string name){
	this->name = name;
	weapon = NULL;
}
HumanB::~HumanB(){
	
}
void HumanB::attack(){
	if(weapon == NULL)
		std::cout << name << " attacks with their " << "Hand" <<std::endl;
	else
		std::cout << name << " attacks with their " << (*weapon).get_type() <<std::endl;
}
void HumanB::setWeapon(Weapon &type){
	this->weapon = &type;
}