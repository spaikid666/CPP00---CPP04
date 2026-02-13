#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j;
	delete i;

	std::cout << std::endl;
    Cat c1;
    c1.setIdea(0, "I want tuna");

    Cat c2 = c1;
    c1.setIdea(0, "I want milk");

	std::cout << std::endl;
	c1.makeSound();
	c2.makeSound();
	std::cout << std::endl;

	std::cout << std::endl;
    std::cout << "c1 idea: " << c1.getIdea(0) << std::endl;
    std::cout << "c2 idea: " << c2.getIdea(0) << std::endl;
	std::cout << std::endl;

    Dog d1;
    d1.setIdea(0, "Ball!");

    Dog d2;
    d2 = d1;
    d1.setIdea(0, "Stick!");

	std::cout << std::endl;
	d1.makeSound();
	d2.makeSound();
	std::cout << std::endl;
	
	std::cout << std::endl;
    std::cout << "d1 idea: " << d1.getIdea(0) << std::endl;
    std::cout << "d2 idea: " << d2.getIdea(0) << std::endl;
	std::cout << std::endl;

	return 0;
}
