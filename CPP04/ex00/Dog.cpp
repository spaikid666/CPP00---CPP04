#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "[Dog] Constructor.\n";
}

Dog::Dog (const Dog &other) : Animal(other)
{
    std::cout << "[Dog] Copy Constructor\n";
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "[Dog] Assignment Operator\n";
    if (this != &other)
        _type = other._type;
    return *this;
}

Dog::~Dog ()
{
    std::cout << "[Dog] Destructor\n";
}

void Dog::makeSound() const
{
    std::cout << "[" << this->getType() << "]" << ": Woof Woof\n";
}