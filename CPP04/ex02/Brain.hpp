# ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	public:
		Brain(void);
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

    	void setIdea(int idx, const std::string& idea);
    	std::string getIdea(int idx) const;

	private:
		std::string ideas[100];
};

# endif