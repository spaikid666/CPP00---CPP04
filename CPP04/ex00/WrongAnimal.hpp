# ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
    public:
        WrongAnimal(void);
		WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal &other);
        WrongAnimal &operator=(const WrongAnimal &other);
		virtual ~WrongAnimal(void);

		std::string getType() const;
        void makeSound() const;

    protected:
        std::string _type;
};

# endif