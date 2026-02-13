#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called\n";
    *this = other;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
        this->_fixedPointValue = other._fixedPointValue;
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}
