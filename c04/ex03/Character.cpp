#include "Character.hpp"

Character::Character(){
	std::cout << "Character Construct Call" << std::endl;
	Name = "None";
	for(int i = 0; i < 4; i++)
	{
		idx[i] = 0;
		Inventory[i] = 0;
	}
}
Character::Character(std::string name){
	std::cout << "Given name Character Construct Call" << std::endl;
	Name = name;
	for(int i = 0; i < 4; i++)
	{
		idx[i] = 0;
		Inventory[i] = 0;
	}
}
Character::~Character(){
	std::cout << "Character Destruct Call" << std::endl;
	for(int i = 0; i < 4; i++)
		delete Inventory[i];
}
Character::Character(const Character &a){
	std::cout << "Character Copy Construct Call" << std::endl;
	Name = a.getName();
	for(int i = 0; i < 4; i++)
	{
		if(Inventory[i] != NULL)
			delete Inventory[i];
		if(a.idx[i] == 1)
			Inventory[i] = a.Inventory[i]->clone();
		else
			Inventory[i] = NULL;
		idx[i] = a.idx[i];
	}
}
Character& Character::operator=(const Character &a){
	std::cout << "Character assignment operator Call" << std::endl;
	if (this != &a)
	{
		Name = a.getName();
		for (int i = 0; i < 4; i++)
		{
			if(Inventory[i] != NULL)
				delete Inventory[i];
			if (a.idx[i] == 1)
				Inventory[i] = a.Inventory[i]->clone();
			else
				Inventory[i] = NULL;
			idx[i] = a.idx[i];
		}
	}
	return *this;
}
std::string const & Character::getName() const {
	return this->Name;
}
void Character::equip(AMateria* m){
	for(int i = 0; i < 4; i++)
	{
		if(idx[i] == 0)
		{
			if (Inventory[i] != NULL)
				delete Inventory[i];
			Inventory[i] = m;
			idx[i] = 1;
			return;
		}
	}
}
void Character::unequip(int idx){
	if(Inventory[idx] == NULL)
		return;
	this->idx[idx] = 0;
}
void Character::use(int idx, ICharacter& target) {
	if(this->idx[idx] == 1)
		Inventory[idx]->use(target);
}