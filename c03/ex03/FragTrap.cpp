#include "FragTrap.hpp"
FragTrap::FragTrap() : ClapTrap("name"){
	std::cout << "constructor called name FragTrap !" <<std::endl;
	Hit_point =100;
	Energy_points = 100;
	Attack_damage = 30;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name){
	std::cout << "constructor called " << name << " FragTrap !" <<std::endl;
	Hit_point =100;
	Energy_points = 100;
	Attack_damage = 30;
}
FragTrap::~FragTrap(){
	std::cout << "dstroyed " << name << " FragTrap !" <<std::endl;
}
FragTrap::FragTrap(const FragTrap &a){
	std::cout << "Copy constructor called FragTrap" <<std::endl;
	Hit_point = a.Hit_point;
	Energy_points = a.Energy_points;
	Attack_damage = a.Attack_damage;
	name = a.name;
}
FragTrap& FragTrap::operator=(const FragTrap &a){
	std::cout << "Copy assignment operator called FragTrap" << std::endl;
	if (this != &a)
	{
		Hit_point = a.Hit_point;
		Energy_points = a.Energy_points;
		Attack_damage = a.Attack_damage;
		name = a.name;
	}
	return *this;
}

void FragTrap::highFivesGuys(void){
	std::cout << "highFivesGuys !! i'm " << name << "!!" << std::endl;
}