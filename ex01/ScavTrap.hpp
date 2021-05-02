
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <locale.h>

class ScavTrap
{
private:
	static const int	_maxhitpnt = 100;
	static const int	_maxenrgpnt = 50;
	static const int	_lvl = 1;
	std::string			_name;
	static const int	_meldmg = 20;
	static const int	_rngdmg = 15;
	static const int	_armdmgred = 3;
	

public:
	int					hitpnt;
	int					enrgpnt;
	ScavTrap(void);
	ScavTrap(std::string name);
	~ScavTrap(void);
	ScavTrap(const ScavTrap &cpScavTrap);
	ScavTrap			&operator=(const ScavTrap &cpScavTrap);
	void				rangedAttack(std::string const & target);
	void				meleeAttack(std::string const & target);
	int					takeDamage(unsigned int amount);
	void				beRepaired(unsigned int amount);
	unsigned int		challengeNewcomer(std::string const & target);
};

#endif