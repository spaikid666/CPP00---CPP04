#include "Zombie.hpp"

Zombie::Zombie() : name("nameless") {}

Zombie::~Zombie() {}

void	Zombie::setName(std::string _name)
{
	name = _name;
}

void	Zombie::announce ()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
