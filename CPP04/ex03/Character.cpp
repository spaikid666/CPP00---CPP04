#include "Character.hpp"
#include "AMateria.hpp"

Character::Character (std::string const& name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character (void)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character (const Character &other) : _name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i] == NULL)
			this->_inventory[i] = NULL;
		else
			this->_inventory[i] = other._inventory[i]->clone();
	}
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {   
		_name = other._name;

		for (int i = 0; i < 4; i++)
		{
			if (other._inventory[i] == NULL)
			{
				if (this->_inventory[i] != NULL)
					delete(_inventory[i]);
				this->_inventory[i] = NULL;
			}
			else
			{
				if (this->_inventory[i] != NULL)
					delete(_inventory[i]);
				this->_inventory[i] = other._inventory[i]->clone();
			}
		}
	}

    return *this;
}

Character::~Character ()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete(_inventory[i]);
	}
}

void Character::equip(AMateria* m)
{
	if (m == NULL)
		return;
	
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			break;
		}
	}

	return;
}

void Character::unequip(int idx)
{
	if (idx >=0 && idx <= 3)
		this->_inventory[idx] = NULL;
	else
		return;
}

void Character::use(int idx, ICharacter& target)
{
	if (!(idx >=0 && idx <= 3))
		return;
	else if (!this->_inventory[idx])
		return;
	else
		this->_inventory[idx]->use(target);
}

std::string const & Character::getName() const
{
	return this->_name;
}