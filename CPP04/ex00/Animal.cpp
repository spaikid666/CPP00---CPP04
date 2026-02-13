#include "Animal.hpp"

Animal::Animal () : _type("Animal")
{
    std::cout << "[Animal] Default Constructor called\n";
}

Animal::Animal (std::string type) : _type(type)
{
	std::cout << "[Animal] Custom Constructor Called, Type: " << type << std::endl;
}

Animal::Animal (const Animal &other) : _type(other._type)
{
    std::cout << "[Animal] Copy Constructor\n";
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "[Animal] Assignment Operator\n";
    if (this != &other)
        _type = other._type;
    return *this;
}

Animal::~Animal ()
{
    std::cout << "[Animal] Destructor\n";
}

std::string Animal::getType() const
{
    return (this->_type);
}

void Animal::makeSound() const
{
	std::cout << "[Animal]" << ": Generic animal noise that an animal does.\n";
}