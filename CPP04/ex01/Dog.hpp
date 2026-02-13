#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		virtual ~Dog();

		virtual void makeSound() const;
		void setIdea(int idx, const std::string& idea);
		std::string getIdea(int idx) const;
		void generateIdea() const;

	private:
		Brain *brain;
};

#endif
