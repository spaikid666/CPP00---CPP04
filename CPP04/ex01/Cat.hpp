# ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat &other);
        Cat &operator=(const Cat &other);
        virtual ~Cat();

        virtual void makeSound() const;
		void setIdea(int idx, const std::string& idea);
		std::string getIdea(int idx) const;
		void generateIdea() const;

	private:
		Brain *brain;
};

# endif