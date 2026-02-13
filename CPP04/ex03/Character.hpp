# ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character(std::string const& name);
	
		Character(void);
		Character(const Character &other);
        Character &operator=(const Character &other);
		virtual ~Character(void);

		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

		virtual std::string const & getName() const;

	private:
		std::string _name;
		AMateria* _inventory[4];
};

#endif