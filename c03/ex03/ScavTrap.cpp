#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("name"){
	std::cout << "constructor called name ScavTrap !" <<std::endl;
	Attack_damage = 50;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	std::cout << "constructor called " << name << " ScavTrap !" <<std::endl;
	Attack_damage = 50;
}
ScavTrap::~ScavTrap(){
	std::cout << "dstroyed " << name << " ScavTrap !" <<std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &a){
	std::cout << "Copy constructor called ScavTrap" << std::endl;
	Attack_damage = a.Attack_damage;
	name = a.name;
	Energy_points = a.Energy_points;
	Hit_point = a.Hit_point;
}
ScavTrap& ScavTrap::operator=(const ScavTrap &a){
	std::cout << "Copy assignment operator called ScavTrap" << std::endl;
	if(this != &a)
	{
		Attack_damage = a.Attack_damage;
		name = a.name;
		Energy_points = a.Energy_points;
		Hit_point = a.Hit_point;
	}
	return *this;
}
void ScavTrap::attack(const std::string &target){
	if(Energy_points > 0)
	{
		Energy_points--;
		std::cout << "ScavTrap " << name << " attacks " << target << " , causing " << Attack_damage << " points of damage!" << std::endl;
	}
}
void ScavTrap::guardGate(){
	std::cout << name << " is "<<"now guardGate mode !" <<std::endl;
}
