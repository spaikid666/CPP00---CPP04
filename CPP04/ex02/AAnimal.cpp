#include "AAnimal.hpp"

AAnimal::AAnimal () : _type("AAnimal")
{
    std::cout << "[AAnimal] Default Constructor called\n";
}

AAnimal::AAnimal (std::string type) : _type(type)
{
	std::cout << "[AAnimal] Custom Consttypeructor Called, Type: " << type << std::endl;
}

AAnimal::AAnimal (const AAnimal &other) : _type(other._type)
{
    std::cout << "[AAnimal] Copy Constructor\n";
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
    std::cout << "[AAnimal] Assignment Operator\n";
    if (this != &other)
        _type = other._type;
    return *this;
}

AAnimal::~AAnimal ()
{
    std::cout << "[AAnimal] Destructor\n";
}

std::string AAnimal::getType() const
{
    return (this->_type);
}

void AAnimal::generateIdea() const
{
	std::cout << "[" << this->getType() << "]" << ": There is no brain" << std::endl;
}