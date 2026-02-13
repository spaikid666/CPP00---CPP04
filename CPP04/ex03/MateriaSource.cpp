#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource ()
{
	for (int i = 0; i < 4; i++)
		this->_prototype[i] = NULL;
}

MateriaSource::MateriaSource (const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._prototype[i] == NULL)
			this->_prototype[i] = NULL;
		else
			this->_prototype[i] = other._prototype[i]->clone();
	}

}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
    {  
		for (int i = 0; i < 4; i++)
		{
			if (other._prototype[i] == NULL)
			{
				if (this->_prototype[i] != NULL)
					delete(_prototype[i]);
				this->_prototype[i] = NULL;
			}
			else
			{
				if (this->_prototype[i] != NULL)
					delete(_prototype[i]);
				this->_prototype[i] = other._prototype[i]->clone();
			}
		}
	}

	return *this;
}

MateriaSource::~MateriaSource ()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_prototype[i] != NULL)
			delete(this->_prototype[i]);
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_prototype[i] == NULL)
		{
			this->_prototype[i] = m;
			return;
		}
	}
	delete(m);
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_prototype[i] != NULL)
		{
			if (_prototype[i]->getType() == type)
				return (_prototype[i]->clone());
		}
	}
	return (NULL);
}