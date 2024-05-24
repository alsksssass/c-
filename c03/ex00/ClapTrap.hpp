#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <iostream>

class ClapTrap {
private:
	std::string name;
	int Hit_point;
	int Energy_points;
	int Attack_damage;
public:
	ClapTrap();
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap(const ClapTrap &a);
	ClapTrap &operator=(const ClapTrap &a);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif // CLAPTRAP_HPP