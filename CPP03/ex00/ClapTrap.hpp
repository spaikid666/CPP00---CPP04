# ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(const std::string _name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap(void);

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		const std::string &getName(void) const;
		unsigned int getHitPoints(void) const;
		unsigned int getEnergyPoints(void) const;
		unsigned int getAttackDamage(void) const;

	private:
		std::string	 name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;
};

# endif
