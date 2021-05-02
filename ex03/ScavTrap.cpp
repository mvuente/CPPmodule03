#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_mhp = 100;
	this->_mep = 50;
	this->_ep = 50;
	this->_hp = 100;
	this->_meldmg = 20;
	this->_rngdmg = 15;
	this->_armdmgred = 3;
	this->_typename = "железяка-падальщик ";
	this->_who = "Scavtrap ";
	this->_actedrng = "Оглушительный хохот Scavtrap'а ";
	this->_actedmel = " обрушил старую батарею на ";
	this->_whod = " зазевался и ";
	this->_dmg = " повреждений. Фигня! Починим!";
	this->_death = " получил последний удар. Запчасти освободились. Налетай, братва!";
	this->_rpr = " под случайным фонарем смог получить ";
    std::cout << "На свалке собран " << this->_typename << " " << name << std::endl;
    return ;
}

ScavTrap::ScavTrap(const ScavTrap &cpScavTrap)
{
    *this = cpScavTrap;
    return ;
}

ScavTrap		&ScavTrap::operator=(const ScavTrap &cpScavTrap)
{
    if (this != &cpScavTrap)
    {
		this->_mhp = cpScavTrap._mhp;
		this->_mep = cpScavTrap._mep;
		this->_ep = cpScavTrap._ep;
		this->_hp = cpScavTrap._hp;
		this->_meldmg = cpScavTrap._meldmg;
		this->_rngdmg = cpScavTrap._rngdmg;
		this->_armdmgred = cpScavTrap._armdmgred;
		this->_name = cpScavTrap._name;
		this->_typename = cpScavTrap._typename;
		this->_who = cpScavTrap._who;
		this->_actedrng = cpScavTrap._actedrng;
		this->_actedmel = cpScavTrap._actedmel;
		this->_whod = cpScavTrap._whod;
		this->_dmg = cpScavTrap._dmg;
		this->_death = cpScavTrap._death;
		this->_rpr = cpScavTrap._rpr;
    }
	return (*this);
}

std::string		ScavTrap::getName(void)
{
	return (this->_name);
}

unsigned int	ScavTrap::challengeNewcomer(std::string const & target)
{
	std::string		challengeset[5] = { "solve zagadka", "open a door", "clean up, please", "scratch my back", "count to ten"};
	std::string		challenge;

	srand(time(0));
	if (this->_ep < 25)
	{
		std::cout << "Ой! Что-то мне не думается." << std::endl;
		return (0);
	}
	this->_ep -= 25;
	challenge = challengeset[rand() % 5];
	std::cout << "Scavtrap " << this->_name << " задумался и попросил " << challenge << ". ";
	if (challenge == "solve zagadka")
	{
		std::cout << "Решение загадки зациклило код у " << target << " , и он получает 10 пойнтов урона!" << std::endl;
		return (10);
	}
	else if (challenge == "open a door")
	{
		std::cout << target << " не может открыть указанную дверь - она нарисована на стене. Ха-ха." << std::endl;
		return (6);
	}
	else if (challenge == "clean up, please")
	{
		std::cout << target << " попробовал убрать лужу масла на полу и подскользнулся. Мелочь, а приятно!"<< std::endl;
		return (8);
	}
	else if (challenge == "scratch my back")
	{
		std::cout << target << " пытается почесать спину " << this->_name << " и получает электрический разряд. Хе-хе!" << std::endl;
		return (9);
	}
	std::cout << "Неееет, " << target << ", надо считать комплексными числами! Заблокируем твой CPU!" << std::endl;
	return (20);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << this->_typename << this->_name << " отправлен обратно на свалку" << std::endl;
    return ;
}