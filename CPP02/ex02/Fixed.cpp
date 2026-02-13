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
    if (this != &other)
        this->_fixedPointValue = other.getRawBits();
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
    this->_fixedPointValue = static_cast<int>(roundf(n * (1 << _fractionalBits)));
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
    return static_cast<float>(this->_fixedPointValue) / static_cast<float>(1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return this->_fixedPointValue >> _fractionalBits;
}

bool Fixed::operator>(const Fixed &other) const
{
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->getRawBits() != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed res;
    res.setRawBits(this->getRawBits() + other.getRawBits());
    return res;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed res;
    res.setRawBits(this->getRawBits() - other.getRawBits());
    return res;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed res;
    long long a = static_cast<long long>(this->getRawBits());
    long long b = static_cast<long long>(other.getRawBits());
    long long raw = (a * b) >> _fractionalBits;
    res.setRawBits(static_cast<int>(raw));
    return res;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    if (other.getRawBits() == 0)
    {
        Fixed res;
        res.setRawBits(0);
        return res;
    }

    Fixed res;
    long long a = static_cast<long long>(this->getRawBits());
    long long raw = (a << _fractionalBits) / static_cast<long long>(other.getRawBits());
    res.setRawBits(static_cast<int>(raw));
    return res;
}

Fixed &Fixed::operator++(void)
{
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->_fixedPointValue++;
    return temp;
}

Fixed &Fixed::operator--(void)
{
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->_fixedPointValue--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
    o << i.toFloat();
    return o;
}
