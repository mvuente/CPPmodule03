
#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void)
{
	std::cout << "Создание Трапа " << std::endl;
	return ;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name)

{
	this->_mhp = 60;
	this->_mep = 120;
	this->_ep = 120;
	this->_hp = 60;
	this->_meldmg = 60;
	this->_rngdmg = 5;
	this->_armdmgred = 0;
	this->_typename = "panzer-железяка ";
	this->_who = "Неторопливый Ninjatrap ";
	this->_actedrng = " кинул снежком ";
	this->_actedmel = " упал сверху на ";
	this->_whod = " не успел спрятаться в панцирь и ";
	this->_dmg = " повреждений. Бестолковая черепаха!";
	this->_death = " обиделся и решил прекратить бойню. Ну вас всех! ";
	this->_rpr = " помедитировал и получил ";
	std::cout << "Из тьмы вынырнул " << this->_typename << " " << this->_name << " Banzzzzaaaay!" << std::endl;
	return ;
}

NinjaTrap::NinjaTrap(const NinjaTrap &cpNinjaTrap)
{
	*this = cpNinjaTrap;
	return ;
}

NinjaTrap		&NinjaTrap::operator=(const NinjaTrap &cpNinjaTrap)
{
	if (this != &cpNinjaTrap)
	{
		this->_mhp = cpNinjaTrap._mhp;
		this->_mep = cpNinjaTrap._mep;
		this->_ep = cpNinjaTrap._ep;
		this->_hp = cpNinjaTrap._hp;
		this->_meldmg = cpNinjaTrap._meldmg;
		this->_rngdmg = cpNinjaTrap._rngdmg;
		this->_armdmgred = cpNinjaTrap._armdmgred;
		this->_name = cpNinjaTrap._name;
		this->_typename = cpNinjaTrap._typename;
		this->_who = cpNinjaTrap._who;
		this->_actedrng = cpNinjaTrap._actedrng;
		this->_actedmel = cpNinjaTrap._actedmel;
		this->_whod = cpNinjaTrap._whod;
		this->_dmg = cpNinjaTrap._dmg;
		this->_death = cpNinjaTrap._death;
		this->_rpr = cpNinjaTrap._rpr;
	}
	return (*this);
}

unsigned int	NinjaTrap::ninjaShoebox(NinjaTrap &ninja)
{
	if (this->_ep < 45)
	{
		std::cout << "Эхх... Убил бы тебя, да сил не хватает." << std::endl;
		return (0);
	}
	std::cout << this->_name << " дружески хлопает по голове " << ninja.getName() << " и глова отваливается. ";
	return (45);
}

unsigned int	NinjaTrap::ninjaShoebox(FragTrap &frag)
{
	if (this->_ep < 35)
	{
		std::cout << "Ладно, живи, пока я подзаряжаюсь." << std::endl;
		return (0);
	}
	std::cout << this->_name << " втыкает шпильку в единственный глаз " << frag.getName() << " Попробуй бой в темноте, железячишка! ";
	return (35);
}

unsigned int	NinjaTrap::ninjaShoebox(ScavTrap &scav)
{
	if (this->_ep < 25)
	{
		std::cout << "Трепись, трепло. У меня батарейка села!" << std::endl;
		return (0);
	}
	std::cout << this->_name << " ломает устройство речи " << scav.getName() << " Помолчи чуток, трепло! ";
	return (25);
}


NinjaTrap::~NinjaTrap(void)
{
	std::cout << this->_typename << this->_name << " отправлен на перепрошивку" << std::endl;
	return ;
}