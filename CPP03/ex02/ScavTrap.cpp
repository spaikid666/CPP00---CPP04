#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
	std::cout << "Constructor Called, ScavTrap '" << this->name << "' created.\n\n";
}

ScavTrap::ScavTrap(const std::string &_name) : ClapTrap(_name)
{
	this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
	std::cout << "Constructor Called, ScavTrap '" << this->name << "' created.\n\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "Copy Constructor Called, ScavTrap '" << this->name << "' copied.\n\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap Copy Assignment Operator Called.\n\n";
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor Called, ScavTrap '" << this->name << "' destroyed.\n\n";
}

void ScavTrap::attack (const std::string &target)
{
	if (hitPoints == 0)
		return;
	
	if (energyPoints == 0)
	{
		std::cout << "ScavTrav '" << name << "' run out of energy and shut down!\n\n";
		return;
	}

	std::cout << "ScavTrav '" << name << "' attacks '" << target << "' in its own an pretty unique way!\n\n";
	
	if (energyPoints - 10 <= 0)
		energyPoints = 0;

	else
		energyPoints = energyPoints - 10;

}

void ScavTrap::guardGate(void)
{
	if (hitPoints == 0)
		return;
	
	if (energyPoints == 0)
	{
		std::cout << "ClapTrap '" << name << "' run out of energy and shut down!\n\n";
		return;
	}

    std::cout << "ScavTrap '" << name << "' panicked and now is in Gate-Keeper mode but there are no gates arround ... WTF!!??.\n\n";
}