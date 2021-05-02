#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "i'm void" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name)

{
    std::cout << YELLOW "С конвейера сошел очередной железяка Claptrap. Назовем его " << this->_name << "." DEFAULT << std::endl;
    return ;
}

ClapTrap::ClapTrap(const ClapTrap &cpClapTrap)
{
    *this = cpClapTrap;
    return ;
}

ClapTrap		&ClapTrap::operator=(const ClapTrap &cpClapTrap)
{
    if (this != &cpClapTrap)
    {
    	this->_mhp = cpClapTrap._mhp;
		this->_mep = cpClapTrap._mep;
		this->_ep = cpClapTrap._ep;
		this->_hp = cpClapTrap._hp;
		this->_meldmg = cpClapTrap._meldmg;
		this->_rngdmg = cpClapTrap._rngdmg;
		this->_armdmgred = cpClapTrap._armdmgred;
		this->_name = cpClapTrap._name;
		this->_typename = cpClapTrap._typename;
		this->_who = cpClapTrap._who;
		this->_actedrng = cpClapTrap._actedrng;
		this->_actedmel = cpClapTrap._actedmel;
		this->_whod = cpClapTrap._whod;
		this->_dmg = cpClapTrap._dmg;
		this->_death = cpClapTrap._death;
		this->_rpr = cpClapTrap._rpr;
    }
	return (*this);
}

void			ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << this->_who << this->_name << this->_actedrng << target <<  " и нанес ему " << this->_rngdmg << " points of damage!" << std::endl;
	return ;
}

void			ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << this->_who << this->_name << this->_actedmel << target <<  " и нанес " << this->_meldmg << " points of damage!" << std::endl;
	return ;
}

int				ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_armdmgred > (int)amount)
		amount = 0;
	else
		amount -=  this->_armdmgred;
	if (this->_hp < int(amount))
		amount = this->_hp;
	std::cout << RED << this->_name << this->_whod << "получил " << amount << this->_dmg << DEFAULT << std::endl;
	this->_hp -= amount;
	if (this->_hp == 0)
	{
		std::cout << this->_name << this->_death << std::endl;
        return (0);
	}
    return (1);
}

void			ClapTrap::beRepaired(unsigned int amount)
{
	if ((this->_mhp - this->_hp) < int(amount))
		amount = this->_mhp - this->_hp;
	std::cout << GREEN << this->_who << this->_name << this->_rpr << amount << " пойнтов жизни" << " и ";
	this->_hp += amount;
	if ((this->_mep - this->_ep) < int(amount))
		amount = this->_mep - this->_ep;
	std::cout << amount << " пойнтов энергии" DEFAULT << std::endl;
	this->_ep += amount;
    return ;
}

std::string		ClapTrap::getName(void)
{
	return (this->_name);
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Железяка " << this->_name << " больше не нужен" << std::endl;
    return ;
}