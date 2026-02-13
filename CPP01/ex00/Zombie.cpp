#include "Zombie.hpp"

Zombie::Zombie (std::string name) : name(name) {}

Zombie::~Zombie()
{
	std::cout << "Zombie " << "'" << name << "'" << " has been destroyed.\n";
}

void	Zombie::announce ()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
