
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <locale.h>

class FragTrap
{
private:
	static const int	_maxhitpnt = 100;
	static const int	_maxenrgpnt = 100;
	static const int	_lvl = 1;
	std::string			_name;
	static const int	_meldmg = 30;
	static const int	_rngdmg = 20;
	static const int	_armdmgred = 5;
	

public:
	int					hitpnt;
	int					enrgpnt;
	FragTrap(void);
	FragTrap(std::string name);
	~FragTrap(void);
	FragTrap(const FragTrap &cpFragTrap);
	FragTrap			&operator=(const FragTrap &cpFragTrap);
	void				rangedAttack(std::string const & target);
	void				meleeAttack(std::string const & target);
	int					takeDamage(unsigned int amount);
	void				beRepaired(unsigned int amount);
	unsigned int		vaulthunter_dot_exe(std::string const & target);
};

#endif
