
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <locale.h>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(std::string name);
	virtual ~FragTrap(void);
	FragTrap(const FragTrap &cpFragTrap);
	FragTrap			&operator=(const FragTrap &cpFragTrap);
	unsigned int		vaulthunter_dot_exe(std::string const & target);

};

#endif
