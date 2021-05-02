#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : _name(name)
{
	this->hitpnt = 100;
	this->enrgpnt = 100;
    std::cout << "Из измельчителя вывалился железяка-с-чипом " << name << " Viva la ROBOLUTION!" << std::endl;
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
        this->_name = cpFragTrap._name;
        this->hitpnt = cpFragTrap.hitpnt;
	    this->enrgpnt = cpFragTrap.enrgpnt;
    }
	return (*this);
}

void			FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "Крутой Fragtrap " << this->_name << " запулил веник в " << target <<  " и нанес ему " << this->_rngdmg << " points of damage!" << std::endl;
	return ;
}

void			FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "Крутой Fragtrap " << this->_name << " ударил манипулятором " << target <<  " и нанес " << this->_meldmg << " points of damage!" << std::endl;
	return ;
}

int				FragTrap::takeDamage(unsigned int amount)
{
	if (this->_armdmgred > (int)amount)
		amount = 0;
	else
		amount -=  this->_armdmgred;
	if (this->hitpnt < int(amount))
		amount = this->hitpnt;
	std::cout << "Обороняясь, Fragtrap " << this->_name << " получил " << amount << " повреждений. Бедная жестянка!" << std::endl;	
	this->hitpnt -= amount;
	if (this->hitpnt == 0)
	{
		std::cout << this->_name << " не вынес удара, его единственный глаз потух, а колесо сдулось." << std::endl;
        return (0);
	}
    return (1);
}

void			FragTrap::beRepaired(unsigned int amount)
{
	if ((this->_maxhitpnt - this->hitpnt) < int(amount))
		amount = this->_maxhitpnt - this->hitpnt;
	std::cout << "Fragtrap " << this->_name << " нашел розетку и получил " << amount << " пойнтов энергии" << std::endl;
	this->hitpnt += amount;
    return ;
}

unsigned int	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string		attackset[5] = { "rubber_ducky!", "crazygun!", "meeaat!", "chumabot!", "neuro_hammer!"};
	std::string		attack;

	srand(time(0));
	if (this->enrgpnt < 25)
	{
		std::cout << "Уууупсс... силенок на атаку не хватило. Извините." << std::endl;
		return (0);
	}
	this->enrgpnt -= 25;
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
    std::cout << "Железяка-с-чипом " << this->_name << " больше не нужен" << std::endl;
    return ;
}