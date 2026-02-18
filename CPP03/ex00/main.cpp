#include "ClapTrap.hpp"

int main()
{
	ClapTrap ct1 ("CL4P-TP");
	ClapTrap ct2 ("CL3P-TP");
	int	turn = 0;

	std::cout << "Oh no!, There are more than one ClapTraps in the same square meter\n\n";
	std::cout << "Everybody knows that ClapTraps are territorial beings, get ready for the battle!\n";

	/* Scenario 1 - Both run out of energy
	while ((ct1.getEnergyPoints() > 0 && ct1.getHitPoints() > 0) ||
       (ct2.getEnergyPoints() > 0 && ct2.getHitPoints() > 0))
	{
		if (turn % 2 == 0)
		{
			ct1.attack(ct2.getName());
			ct2.takeDamage(ct1.getAttackDamage());

			ct2.attack(ct1.getName());
			if (ct2.getHitPoints() > 0)
				ct1.takeDamage(ct2.getAttackDamage());
		}

		else
		{
			ct1.beRepaired(0);
			ct2.beRepaired(0);
		}
		turn++;
	}

	std::cout << "Both ClapTraps run out of energy, they both suck, what a waste of resources!\n\n";
 */
	/* Scenario 2 - They do real damage  */
	while ((ct1.getEnergyPoints() > 0 && ct1.getHitPoints() > 0) ||
       (ct2.getEnergyPoints() > 0 && ct2.getHitPoints() > 0))
	{
		if (turn % 2 == 0)
		{
			ct1.attack(ct2.getName());
			ct2.takeDamage(4);

			ct2.attack(ct1.getName());
			if (ct2.getHitPoints() > 0)
				ct1.takeDamage(3);
		}

		else
		{
			ct1.beRepaired(2);
			ct2.beRepaired(2);
		}
		turn++;
	}
	std::cout << "*** " << ct1.getName() << " won! ***\n\n";

	return 0;
}