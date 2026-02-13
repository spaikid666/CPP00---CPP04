#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "Constructor Called, FragTrap '" << this->name << "' created.\n\n";
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "Constructor Called, FragTrap '" << this->name << "' created.\n\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "Copy Constructor Called, FragTrap '" << this->name << "' copied.\n\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap Copy Assignment Operator Called.\n\n";
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor Called, FragTrap '" << this->name << "' destroyed.\n\n";
}

void FragTrap::highFiveGuys()
{
    std::cout << std::cout << "FragTrap " << this->name << " requests a high five! 🙏\n\n";
    std::cout << std::cout << "The request of FragTrap " << this->name << " was successfully ignored!\n\n";
}