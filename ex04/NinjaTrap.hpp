
#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include <iostream>
#include <locale.h>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class NinjaTrap : virtual public ClapTrap
{
public:
	NinjaTrap(void);
	NinjaTrap(std::string name);
	virtual ~NinjaTrap(void);
	NinjaTrap(const NinjaTrap &cpNinjaTrap);
	NinjaTrap			&operator=(const NinjaTrap &cpNinjaTrap);
	unsigned int		ninjaShoebox(NinjaTrap &ninja);
	unsigned int		ninjaShoebox(FragTrap &frag);
	unsigned int		ninjaShoebox(ScavTrap &scav);

};


#endif
