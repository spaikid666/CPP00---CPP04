# ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	
	public:
		Fixed(void);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed(void);
	
    	int     getRawBits(void) const;
    	void    setRawBits(int const raw);

	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
};

# endif