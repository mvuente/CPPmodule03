
#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name) : NinjaTrap(), FragTrap()

{
	this->_name = name;
	this->_mhp = FragTrap::_mhp;
	this->_mep = NinjaTrap::_mep;
	this->_ep = NinjaTrap::_ep;
	this->_hp = FragTrap::_hp;
	this->_meldmg = NinjaTrap::_meldmg;
	this->_rngdmg = FragTrap::_rngdmg;
	this->_armdmgred = FragTrap::_armdmgred;
	this->_typename = "мега-супер-железяка ";
	this->_who = "Крутой Supertrap ";
	this->_actedrng = FragTrap::_actedrng;
	this->_actedmel = NinjaTrap::_actedmel;
	this->_whod = " позволил себя ударить и ";
	this->_dmg = " повреждений. ХаХа!";
	this->_death = " отключился. Но все впереди. He'll be back!";
	this->_rpr = " сжал булки и сгенерировал себе ";
	std::cout << "Из двух недоТрапов собран " << this->_typename << " " << this->_name << "! Берегитесь, человечишки!" << std::endl;
	return ;
}

SuperTrap::SuperTrap(const SuperTrap &cpSuperTrap)
{
	*this = cpSuperTrap;
	return ;
}

SuperTrap		&SuperTrap::operator=(const SuperTrap &cpSuperTrap)
{
	if (this != &cpSuperTrap)
	{
		this->_mhp = cpSuperTrap._mhp;
		this->_mep = cpSuperTrap._mep;
		this->_ep = cpSuperTrap._ep;
		this->_hp = cpSuperTrap._hp;
		this->_meldmg = cpSuperTrap._meldmg;
		this->_rngdmg = cpSuperTrap._rngdmg;
		this->_armdmgred = cpSuperTrap._armdmgred;
		this->_name = cpSuperTrap._name;
		this->_typename = cpSuperTrap._typename;
		this->_who = cpSuperTrap._who;
		this->_actedrng = cpSuperTrap._actedrng;
		this->_actedmel = cpSuperTrap._actedmel;
		this->_whod = cpSuperTrap._whod;
		this->_dmg = cpSuperTrap._dmg;
		this->_death = cpSuperTrap._death;
		this->_rpr = cpSuperTrap._rpr;
	}
	return (*this);
}

SuperTrap::~SuperTrap(void)
{
	std::cout << this->_typename << " " << this->_name << " свернулся калачиком и затих. Веслитесь, детки!" << std::endl;
	return ;
}