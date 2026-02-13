#include "Zombie.hpp"

int main()
{
	std::cout << "Creating a heap zombie with newZombie():\n";
	Zombie *heapZombie = newZombie("heapZombie");
	heapZombie->announce();
	delete heapZombie;

	std::cout << "\n";
	std::cout << "Creating a stack zombie witn randomChump():\n";
	randomChump("stackZombie");
}