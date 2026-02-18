#include "ClapTrap.hpp"

ClapTrap::ClapTrap (void) : name("Nameless"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Default Constructor Called, ClapTrap '" << name << "' created.\n\n";
}

ClapTrap::ClapTrap (const std::string _name) : name(_name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Constructor Called, ClapTrap '" << name << "' created.\n\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
	std::cout << "Copy Constructor Called, ClapTrap '" << name << "' copied.\n\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Copy Assignment Operator Called.\n\n";
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap ()
{
	std::cout << "Destructor Called, ClapTrap '" << name << "' destroyed.\n\n";
}

void ClapTrap::attack (const std::string &target)
{
	if (hitPoints == 0)
	{
		std::cout << "The dead body of ClapTrap '" << name << "' lays on the floor motionless ...\n\n";
		return;
	}
	
	if (energyPoints == 0)
	{
		std::cout << "ClapTrap '" << name << "' run out of energy and shut down!\n\n";
		return;
	}

	std::cout << "ClapTrap '" << name << "' attacks '" << target << "'!\n\n";
	energyPoints--;
}

void ClapTrap::takeDamage (unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "Dude, ClapTrap '" << name << "' is already dead, leave him alone!\n\n";
		return;
	}
	
	if (amount >= hitPoints)
        hitPoints = 0;
	
	else
		hitPoints -= amount;

	std::cout << "ClapTrap '" << name << "' took " << amount << " points of damage! (" << energyPoints << " energy points remaining)\n\n";
	
	if (amount == 0)
		std::cout << "Damn, that was lame!\n\n";
}

void ClapTrap::beRepaired (unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "The dead body of ClapTrap '" << name << "' stills there and didn't go anywhere because it's f*cking DEAD!\n\n";
		return;
	}
	
	if (energyPoints == 0)
	{
		std::cout << "ClapTrap '" << name << "' run out of energy and shut down!\n\n";
		return;
	}

	if (hitPoints == 10)
	{
		std::cout << "ClapTrap '" << name << "' repaired itself but it already has max health points, what is it doing!?\n\n";
		std::cout << "Maybe it healed the emotional damaged caused from the last attack received ...\n\n";
		energyPoints--;
		return;
	}

	hitPoints += amount;
	
	std::cout << "ClapTrap '" << name << "' repaired itself and restored " << amount << " health points! (" << energyPoints << " energy points remaining)\n\n";

	energyPoints--;
}

const std::string &ClapTrap::getName (void) const {return name;}
unsigned int ClapTrap::getHitPoints (void) const {return hitPoints;}
unsigned int ClapTrap::getEnergyPoints (void) const {return energyPoints;}
unsigned int ClapTrap::getAttackDamage (void) const {return attackDamage;}