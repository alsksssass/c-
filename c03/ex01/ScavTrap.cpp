#include "ScavTrap.hpp"

using std::cout; using std::endl;

ScavTrap::ScavTrap() : ClapTrap("name"){
	cout << "constructor called name ScavTrap !" <<endl;
	Attack_damage = 50;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	cout << "constructor called " << name << " ScavTrap !" <<endl;
	Attack_damage = 50;
}
ScavTrap::~ScavTrap(){
	cout << "dstroyed " << name << " ScavTrap !" <<endl;
}
ScavTrap::ScavTrap(const ScavTrap &a){
	cout << "Copy constructor called ScavTrap" << endl;
	Attack_damage = a.Attack_damage;
	name = a.name;
	Energy_points = a.Energy_points;
	Hit_point = a.Hit_point;
}
ScavTrap& ScavTrap::operator=(const ScavTrap &a){
	if(this != &a)
	{
		cout << "Copy assignment operator called ScavTrap" << endl;
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
		cout << "ScavTrap " << name << " attacks " << target << " , causing " << Attack_damage << " points of damage!" << endl;
	}
}
void ScavTrap::guardGate(){
	cout << name << " is "<<"now guardGate mode !" <<endl;
}
