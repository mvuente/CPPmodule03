#include <iostream>
#include <locale.h>
#include "FragTrap.hpp"

int main()
{
    setlocale(LC_ALL, "Russian");
    FragTrap    a("FR4G-TP");
    FragTrap    b("Клон");

    a.meleeAttack("Клон");
    if (!b.takeDamage(30))
		return (0);
    a.rangedAttack("Клон");
    if (b.takeDamage(20) == 0)
		return (0);
	a.beRepaired(30);
	a.meleeAttack("Клон");
    if (!b.takeDamage(30))
		return (0);
	a.meleeAttack("Клон");
    if (!b.takeDamage(30))
		return (0);
	if (!a.takeDamage(b.vaulthunter_dot_exe("FR4G-TP")))
		return (0);
	a.meleeAttack("Клон");
	if (!b.takeDamage(30))
		return (0);
    return (0);
}