# ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
    public:
        AAnimal(void);
		AAnimal(std::string type);
        AAnimal(const AAnimal &other);
        AAnimal &operator=(const AAnimal &other);
		virtual ~AAnimal(void);

		std::string getType() const;
        virtual void makeSound() const = 0;
		virtual void generateIdea() const;

    protected:
        std::string _type;
};

# endif