# ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
    public:
        Animal(void);
		Animal(std::string type);
        Animal(const Animal &other);
        Animal &operator=(const Animal &other);
		virtual ~Animal(void);

		std::string getType() const;
        virtual void makeSound() const;
		virtual void generateIdea() const;

    protected:
        std::string _type;
};

# endif