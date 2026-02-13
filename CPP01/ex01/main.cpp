#include "Zombie.hpp"

int main()
{
	int N = 5;

	std::cout << "Creating a horde of " << N << " zombies:\n";
	Zombie *horde = zombieHorde(N, "Zombie");

	for (int i = 0; i < N; i++)
	{
		std::cout << "Zombie " << i + 1 << " has been created\n";
		horde[i].announce();
	}

	std::cout << "\nDeleting the horde:\n";
	delete [] horde;
	for (int i = 0; i < N; i++)
	{
		std::cout << "Zombie " << i + 1 << " has been deleted\n";
	}

	return 0;
}