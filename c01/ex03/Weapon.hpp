#ifndef WEAPON_H
#define WEAPON_H
#include <string>

class Weapon{
	private:
		std::string type;
	public:
		Weapon();
		Weapon(std::string type);
		std::string get_type();
		void setType(std::string type);
};

#endif