#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

/* ARREGLAR ESTOM CLAP TRAP ES EL QUE DEBE DE MORIR PORQUE HE CAMBIADO LAS STATS DE CLAP TRAP A LAS DEL EJERCICIO ANTERIOR */

int main()
{
	ClapTrap ct ("CL4P-TP");
	ScavTrap st ("SC4V-TP");
	int	turn = 0;
	bool dead = 0;

	std::cout << "Oh no!, There are more than one ClapTrap and a ScavTrap in the same square meter\n\n";
	std::cout << "Everybody knows that ClapTraps and ScavTraps are territorial beings, get ready for the battle!\n\n";

	while ((ct.getEnergyPoints() > 0 && ct.getHitPoints() > 0) ||
       (st.getEnergyPoints() > 0 && st.getHitPoints() > 0))
	{
		if (turn % 2 == 0)
		{
			ct.attack(st.getName());
			if (ct.getHitPoints() > 0)
				st.takeDamage(ct.getAttackDamage());

			st.attack(ct.getName());
			if (st.getHitPoints() > 0)
				ct.takeDamage(st.getAttackDamage());
			else if (dead != 1)
			{
				std::cout << "ScavTrap '" << st.getName() << "' died in an atrocious and horrendous way!\n\n";
				dead = 1;
			}
		}

		else
		{
			ct.beRepaired(1);
			if (st.getHitPoints() > 10)
				st.beRepaired(1);
			else
				st.guardGate();
		}
		turn++;
	}

	return 0;
}