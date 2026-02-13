#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal () : _type("WrongAnimal")
{
    std::cout << "[WrongAnimal] Constructor called\n";
}

WrongAnimal::WrongAnimal (std::string type) : _type(type)
{
	std::cout << "[WrongAnimal] Custom Constructor Called, Type: " << type << std::endl;
}

WrongAnimal::WrongAnimal (const WrongAnimal &other) : _type(other._type)
{
    std::cout << "[WrongAnimal] Copy Constructor\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "[WrongAnimal] Assignment Operator\n";
    if (this != &other)
        _type = other._type;
    return *this;
}

WrongAnimal::~WrongAnimal ()
{
    std::cout << "[WrongAnimal] Destructor\n";
}

std::string WrongAnimal::getType() const
{
    return (this->_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "[" << this->getType() << "]" << ": Generic 'Wrong Animal' noise that a 'Wrong Animal' does.\n";
}