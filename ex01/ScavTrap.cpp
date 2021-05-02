#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : _name(name)
{
	this->hitpnt = 100;
	this->enrgpnt = 50;
    std::cout << "На свалке собран очередной железяка-падальщик Scavtrap " << name << std::endl;
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
        this->_name = cpScavTrap._name;
        this->hitpnt = cpScavTrap.hitpnt;
	    this->enrgpnt = cpScavTrap.enrgpnt;
    }
	return (*this);
}

void			ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "Оглушительный хохот Scavtrap'а " << this->_name <<  " нанес " << target << "'у "  << this->_rngdmg << " points of damage!" << std::endl;
	return ;
}

void			ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "Scavtrap " << this->_name << " обрушил старую батарею на " << target <<  " и нанес ему " << this->_meldmg << " points of damage!" << std::endl;
	return ;
}

int				ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_armdmgred > (int)amount)
		amount = 0;
	else
		amount -=  this->_armdmgred;
	if (this->hitpnt < int(amount))
		amount = this->hitpnt;
	std::cout << "Scavtrap " << this->_name << " зазевался и получил " << amount << " повреждений. Фигня! Починим!" << std::endl;	
	this->hitpnt -= amount;
	if (this->hitpnt == 0)
	{
		std::cout << "Этот удар для " << this->_name << " был последним. Запчасти освободились. Налетай, братва!" << std::endl;
        return (0);
	}
    return (1);
}

void			ScavTrap::beRepaired(unsigned int amount)
{
	if ((this->_maxhitpnt - this->hitpnt) < int(amount))
		amount = this->_maxhitpnt - this->hitpnt;
	std::cout << "Scavtrap " << this->_name << " под случайным фонарем смог получить " << amount << " пойнтов энергии" << std::endl;
	this->hitpnt += amount;
    return ;
}

unsigned int	ScavTrap::challengeNewcomer(std::string const & target)
{
	std::string		challengeset[5] = { "solve zagadka", "open a door", "clean up, please", "scratch my back", "count to ten"};
	std::string		challenge;

	srand(time(0));
	if (this->enrgpnt < 25)
	{
		std::cout << "Ой! Что-то мне не думается." << std::endl;
		return (0);
	}
	this->enrgpnt -= 25;
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
    std::cout << "Железяка-падальщик " << this->_name << " отправлен обратно на свалку" << std::endl;
    return ;
}