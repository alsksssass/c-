#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"
class ScavTrap : virtual public ClapTrap {
public:
	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(const ScavTrap &a);
	ScavTrap &operator=(const ScavTrap &a);
	void guardGate();
	void attack(const std::string &target);
};

#endif // SCAVTRAP_HPP