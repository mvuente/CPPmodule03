#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <locale.h>

class ClapTrap
{
protected:
	int					_mhp;
	int					_mep;
	int					_hp;
	int					_ep;
	static const int	_lvl = 1;
	int					_meldmg;
	int					_rngdmg;
	int					_armdmgred;
	std::string			_name;
	std::string			_typename;
	std::string         _who;
	std::string         _actedrng;
    std::string         _actedmel;
    std::string         _whod;
    std::string         _dmg;
    std::string         _death;
    std::string         _rpr;

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	~ClapTrap(void);
	ClapTrap(const ClapTrap &cpClapTrap);
	ClapTrap			&operator=(const ClapTrap &cpClapTrap);
	void				rangedAttack(std::string const & target);
	void				meleeAttack(std::string const & target);
	int					takeDamage(unsigned int amount);
	void				beRepaired(unsigned int amount);
};

#endif
