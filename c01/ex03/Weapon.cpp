#include "Weapon.hpp"

Weapon::Weapon(){
	this->type = "NONE";
}
Weapon::Weapon(std::string type){
	this->type = type;
}
const std::string &Weapon::get_type(){
	return this->type;
}
void Weapon::setType(std::string type){
	this->type = type;
}