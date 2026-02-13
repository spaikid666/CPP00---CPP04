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

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other) {
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called\n";
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called\n";
    this->_fixedPointValue = n << _fractionalBits;
}

Fixed::Fixed(const float n)
{
    std::cout << "Float constructor called\n";
    this->_fixedPointValue = roundf(n * (1 << _fractionalBits));
}

int Fixed::getRawBits(void) const
{
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
    return (float)this->_fixedPointValue / (float)(1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return this->_fixedPointValue >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
    o << i.toFloat();
    return o;
}