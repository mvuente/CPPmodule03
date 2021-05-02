
#ifndef SUPERTRAP_HPP
#define SUPERTRAP_HPP

#include <iostream>
#include <locale.h>
#include "FragTrap.hpp"

#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"

class SuperTrap : public NinjaTrap, public FragTrap
{
public:
	SuperTrap(void);
	SuperTrap(std::string name);
	virtual ~SuperTrap(void);
	SuperTrap(const SuperTrap &cpSuperTrap);
	SuperTrap			&operator=(const SuperTrap &cpSuperTrap);
	unsigned int		SuperShoebox(SuperTrap &super);
	unsigned int		SuperShoebox(FragTrap &frag);
	unsigned int		SuperShoebox(ScavTrap &scav);

};

#endif
