#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "[WrongCat] Constructor.\n";
}

WrongCat::WrongCat (const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "[WrongCat] Copy Constructor\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "[WrongCat] Assignment Operator\n";
    if (this != &other)
        _type = other._type;
    return *this;
}

WrongCat::~WrongCat ()
{
    std::cout << "[WrongCat] Destructor\n";
}

void WrongCat::makeSound() const
{
	std::cout << "[" << this->getType() << "]" << ": RTY%$^#%@WHUJ^&F\n";
}
