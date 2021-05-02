
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <locale.h>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	~ScavTrap(void);
	ScavTrap(const ScavTrap &cpScavTrap);
	ScavTrap			&operator=(const ScavTrap &cpScavTrap);
	unsigned int		challengeNewcomer(std::string const & target);
	std::string			getName(void);
};

#endif