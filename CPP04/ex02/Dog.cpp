#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog"), brain(new Brain())
{
    std::cout << "[Dog] Constructor.\n";
}

Dog::Dog(const Dog &other) : AAnimal(other), brain(new Brain(*other.brain))
{
    std::cout << "[Dog] Copy Constructor\n";
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "[Dog] Assignment Operator\n";
    if (this != &other)
    {
        AAnimal::operator=(other);

        Brain *newBrain = new Brain(*other.brain);
        delete brain;
        brain = newBrain;
    }
    return *this;
}

Dog::~Dog ()
{
    std::cout << "[Dog] Destructor\n";
	delete this->brain;
}

void Dog::makeSound() const
{
    std::cout << "[" << this->getType() << "]" << ": Woof Woof\n";
}

void Dog::setIdea(int idx, const std::string& idea)
{
    brain->setIdea(idx, idea);
}

std::string Dog::getIdea(int idx) const
{
    return brain->getIdea(idx);
}

void Dog::generateIdea() const
{
    std::cout << "[" << getType() << "] idea[0]: " << brain->getIdea(0) << std::endl;
}