#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat"), brain(new Brain())
{
    std::cout << "[Cat] Constructor.\n";
}

Cat::Cat(const Cat &other) : AAnimal(other), brain(new Brain(*other.brain))
{
    std::cout << "[Cat] Copy Constructor\n";
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "[Cat] Assignment Operator\n";
    if (this != &other)
    {
        AAnimal::operator=(other);

        Brain *newBrain = new Brain(*other.brain);
        delete brain;
        brain = newBrain;
    }
    return *this;
}

Cat::~Cat ()
{
    std::cout << "[Cat] Destructor\n";
	delete this->brain;
}

void Cat::makeSound() const
{
    std::cout << "[" << this->getType() << "]" << ": Meoooow\n";
}

void Cat::setIdea(int idx, const std::string& idea)
{
    brain->setIdea(idx, idea);
}

std::string Cat::getIdea(int idx) const
{
    return brain->getIdea(idx);
}

void Cat::generateIdea() const
{
    std::cout << "[" << getType() << "] idea[0]: " << brain->getIdea(0) << std::endl;
}
