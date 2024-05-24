#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("name_clap_name"), FragTrap(), ScavTrap(){
	std::cout << "constructor called name DiamondTrap !" <<std::endl;
	DiamondTrap::name = "name";
	this->Energy_points = ScavTrap::Energy_points;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name+"_clap_name"), FragTrap(name), ScavTrap(name) {
	std::cout << "constructor called " << name << " DiamondTrap !" <<std::endl;
	DiamondTrap::name = name;
	this->Energy_points = ScavTrap::Energy_points;
}
DiamondTrap::~DiamondTrap(){
	std::cout << "dstroyed " << name << " DiamondTrap !" <<std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap &a): ClapTrap(a.name+"_clap_name"), FragTrap(a.name), ScavTrap(a.name) {
	std::cout << "Copy constructor called DiamondTrap" <<std::endl;
	DiamondTrap::name = a.name;
	this->Energy_points = ScavTrap::Energy_points;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap &a){
	if (this != &a)
	{
		std::cout << "Copy assignment operator called DiamondTrap" << std::endl;
		this->name = a.name;
		this->Attack_damage = a.Attack_damage;
		this->Energy_points = a.Energy_points;
		this->Hit_point = a.Hit_point;
		this->ScavTrap::name = a.ScavTrap::name;
	}
	return *this;
}
void DiamondTrap::whoAmI(){
	std::cout << "i'm DiamondTrap my name is " << this->name <<" and my ClapTrap name is " << ClapTrap::name << " thx" << std::endl; 
}
