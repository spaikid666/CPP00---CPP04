#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "[Cat] Constructor.\n";
}

Cat::Cat (const Cat &other) : Animal(other)
{
    std::cout << "[Cat] Copy Constructor\n";
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "[Cat] Assignment Operator\n";
    if (this != &other)
        _type = other._type;
    return *this;
}

Cat::~Cat ()
{
    std::cout << "[Cat] Destructor\n";
}

void Cat::makeSound() const
{
    std::cout << "[" << this->getType() << "]" << ": Meoooow\n";
}