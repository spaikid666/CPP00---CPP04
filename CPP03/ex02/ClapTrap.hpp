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
		void takeDamage(int amount);
		void beRepaired(int amount);

		const std::string &getName(void) const;
		int getHitPoints(void) const;
		int getEnergyPoints(void) const;
		int getAttackDamage(void) const;

	protected:
		std::string	 name;
		int hitPoints;
		int energyPoints;
		int attackDamage;
};

# endif
