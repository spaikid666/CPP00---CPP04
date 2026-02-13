#include "HumanB.hpp"

HumanB::HumanB (const std::string &name) : name(name) {}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack() const
{
	if (weapon)
		std::cout << name << " attacks with their " << (*weapon).getType() << "\n";
	else
		std::cout << name << " attacks with their bare hands\n";
}