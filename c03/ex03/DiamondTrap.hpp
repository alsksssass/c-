#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
class DiamondTrap : public FragTrap, public ScavTrap {
private:
	std::string name;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	~DiamondTrap();
	DiamondTrap(const DiamondTrap &a);
	DiamondTrap &operator=(const DiamondTrap &a);
	void whoAmI();
};

#endif // DIAMONDTRAP_HPP