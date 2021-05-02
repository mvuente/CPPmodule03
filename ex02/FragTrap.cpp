#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)

{
	this->_mhp = 100;
	this->_mep = 100;
	this->_ep = 100;
	this->_hp = 100;
	this->_meldmg = 30;
	this->_rngdmg = 20;
	this->_armdmgred = 5;
	this->_typename = "железяка-с-чипом ";
	this->_who = "Крутой Fragtrap ";
	this->_actedrng = " запулил веник в ";
	this->_actedmel = " ударил манипулятором ";
	this->_whod = "'а настиг коварный удар и он ";
	this->_dmg = " повреждений. Бедная жестянка!";
	this->_death = " не вынес удара, его единственный глаз потух, а колесо сдулось.";
	this->_rpr = " нашел розетку и получил ";
	std::cout << "Из измельчителя вывалился " << this->_typename << " " << name << " Viva la ROBOLUTION!" << std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap &cpFragTrap)
{
    *this = cpFragTrap;
    return ;
}

FragTrap		&FragTrap::operator=(const FragTrap &cpFragTrap)
{
    if (this != &cpFragTrap)
    {
		this->_mhp = cpFragTrap._mhp;
		this->_mep = cpFragTrap._mep;
		this->_ep = cpFragTrap._ep;
		this->_hp = cpFragTrap._hp;
		this->_meldmg = cpFragTrap._meldmg;
		this->_rngdmg = cpFragTrap._rngdmg;
		this->_armdmgred = cpFragTrap._armdmgred;
		this->_name = cpFragTrap._name;
		this->_typename = cpFragTrap._typename;
		this->_who = cpFragTrap._who;
		this->_actedrng = cpFragTrap._actedrng;
		this->_actedmel = cpFragTrap._actedmel;
		this->_whod = cpFragTrap._whod;
		this->_dmg = cpFragTrap._dmg;
		this->_death = cpFragTrap._death;
		this->_rpr = cpFragTrap._rpr;
    }
	return (*this);
}

unsigned int	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string		attackset[5] = { "rubber_ducky!", "crazygun!", "meeaat!", "chumabot!", "neuro_hammer!"};
	std::string		attack;

	if (this->_ep < 25)
	{
		std::cout << "Уууупсс... силенок на атаку не хватило. Извините." << std::endl;
		return (0);
	}
	this->_ep -= 25;
	attack = attackset[rand() % 5];
	std::cout << "Над глазом " << this->_name << " замерцали цифры и... заполучи, фашист, атаку " << attack << " ";
	if (attack == "rubber_ducky")
	{
		std::cout << "Резиновая уточка рулит! " << target << " получает 40 пойнтов урона!" << std::endl;
		return (40);
	}
	else if (attack == "crazygun")
	{
		std::cout << "Не перестану стрелять, пока " << target << " не будет уничтожен! ААААА!" << std::endl;
		return (30);
	}
	else if (attack == "meeaat!")
	{
		std::cout << "Играем в хирурга! Бензопила в помощь! " << target << ", что у тебя внутри?"<< std::endl;
		return (15);
	}
	else if (attack == "chumabot!")
	{
		std::cout << "Безмозглый двойник вызывает коррозию для всех! И немного огоньку для " << target << std::endl;
		return (45);
	}
	std::cout << "Фрагтрап-невропатолог с молоточком крошит всех! " << target << ", как тебе гидромолот в 1000 тонн?"<< std::endl;
	return (60);
}

FragTrap::~FragTrap(void)
{
    std::cout << this->_typename << " " << this->_name << " миссию закончил. Останки положим в морозилку!" << std::endl;
    return ;
}