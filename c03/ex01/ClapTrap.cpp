#include "ClapTrap.hpp"

using std::cout; using std::endl;

ClapTrap::ClapTrap(){
	cout << "constructor called name ClapTrap !" <<endl;
	name = "name";
	Hit_point = 10;
	Energy_points =10;
	Attack_damage = 0;
}
ClapTrap::ClapTrap(std::string name){
	cout << "constructor called " << name << " ClapTrap !" <<endl;
	this->name = name;
	Hit_point = 10;
	Energy_points =10;
	Attack_damage = 0;
}
ClapTrap::~ClapTrap(){
	cout << "dstroyed " << name << " ClapTrap !" <<endl;
}
ClapTrap::ClapTrap(const ClapTrap &a){
	cout << "Copy constructor called" <<endl;
	this->name = a.name;
	this->Hit_point = a.Hit_point;
	this->Energy_points = a.Energy_points;
	this->Attack_damage = a.Attack_damage;
}
ClapTrap& ClapTrap::operator=(const ClapTrap &a){
	if(this != &a)
	{
	cout << "Copy assignment operator called ClapTrap" << endl;
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
		cout << "ClapTrap " << name << " attacks " << target << " , causing " << Attack_damage << " points of damage!" << endl;
	}
}
void ClapTrap::takeDamage(unsigned int amount){
	if(Hit_point <= 0)
	{
		cout << "ClapTrap " << name << " Already Dead !!"<< endl;
		return;
	}
	if ((int)amount > Hit_point)
		Hit_point = 0;
	else
		Hit_point-=amount;
	cout << "ClapTrap " << name << " Damaged " << amount << "!!"<< endl;
	if(Hit_point == 0)
		cout << "ClapTrap " << name << " is Dead !!"<< endl;
}
void ClapTrap::beRepaired(unsigned int amount){
	if(Energy_points > 0)
	{
		Energy_points--;
		Hit_point+=amount;
		cout << "ClapTrap " << name << " Repaired " << amount << "!!"<< endl;
	}
}