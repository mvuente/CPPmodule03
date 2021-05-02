#include <iostream>
#include <locale.h>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int main()
{
    setlocale(LC_ALL, "Russian");
    FragTrap    a("FR4G-TP");
    ScavTrap    b("SC4V-TP");
    NinjaTrap	buono("Good");
    NinjaTrap	brutto("Mad");

	srand(time(0));
    a.meleeAttack("SC4V-TP");
    if (!b.takeDamage(30))
		return (0);
    a.rangedAttack("SC4V-TP");
    if (b.takeDamage(20) == 0)
		return (0);
	b.beRepaired(30);
	a.meleeAttack("SC4V-TP");
    if (!b.takeDamage(30))
		return (0);
	b.meleeAttack("FR4G-TP");
    if (!a.takeDamage(30))
		return (0);
	if (!a.takeDamage(b.challengeNewcomer("FR4G-TP")))
		return (0);
	a.meleeAttack("SC4V-TP");
    if (!b.takeDamage(30))
		return (0);
	b.beRepaired(30);
	if (!b.takeDamage(a.vaulthunter_dot_exe("SC4V-TP")))
		return (0);

	if (!buono.takeDamage(brutto.ninjaShoebox(buono)))
		return (0);
	if (!a.takeDamage(brutto.ninjaShoebox(a)))
		return (0);
	if (!b.takeDamage(brutto.ninjaShoebox(b)))
		return (0);
    return (0);
}