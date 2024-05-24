#include "ClapTrap.hpp"


ClapTrap::ClapTrap(){
	std::cout << "constructor called name ClapTrap !" <<std::endl;
	name = "name";
	Hit_point = 10;
	Energy_points =10;
	Attack_damage = 0;
}
ClapTrap::ClapTrap(std::string name){
	std::cout << "constructor called " << name << " ClapTrap !" <<std::endl;
	this->name = name;
	Hit_point = 10;
	Energy_points =10;
	Attack_damage = 0;
}
ClapTrap::~ClapTrap(){
	std::cout << "dstroyed " << name << " ClapTrap !" <<std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &a){
	std::cout << "Copy constructor called ClapTrap" <<std::endl;
	this->name = a.name;
	this->Hit_point = a.Hit_point;
	this->Energy_points = a.Energy_points;
	this->Attack_damage = a.Attack_damage;
}
ClapTrap& ClapTrap::operator=(const ClapTrap &a){
	if(this != &a)
	{
	std::cout << "Copy assignment operator called ClapTrap" << std::endl;
	this->name = a.name;
	this->Hit_point = a.Hit_point;
	this->Energy_points = a.Energy_points;
	this->Attack_damage = a.Attack_damage;
	}
	return *this;
}
void ClapTrap::attack(const std::string &target){
	if(Energy_points > 0)
	{
		Energy_points--;
		std::cout << "ClapTrap " << name << " attacks " << target << " , causing " << Attack_damage << " points of damage!" << std::endl;
	}
}
void ClapTrap::takeDamage(unsigned int amount){
	if(Hit_point <= 0)
	{
		std::cout << "ClapTrap " << name << " Already Dead !!"<< std::endl;
		return;
	}
	if ((int)amount > Hit_point)
		Hit_point = 0;
	else
		Hit_point-=amount;
	std::cout << name << " Damaged " << amount << "!!"<< std::endl;
	if(Hit_point == 0)
		std::cout << "ClapTrap " << name << " is Dead !!"<< std::endl;
}
void ClapTrap::beRepaired(unsigned int amount){
	if(Energy_points > 0)
	{
		Energy_points--;
		Hit_point+=amount;
		std::cout << "ClapTrap " << name << " Repaired " << amount << "!!"<< std::endl;
	}
}