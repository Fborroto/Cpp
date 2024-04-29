/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:17:23 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/29 05:11:16 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
	std::cout << "(ScavTrap)Constructor Call for : " << name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "(ScavTrap)Destructor  Call for : " << name << std::endl;
	return ;
}
ScavTrap::ScavTrap(const ScavTrap &scavTrap) :  ClapTrap(scavTrap.name)
{
	std::cout << "(ScavTrap)CopyConstructor Call" << std::endl;
	*this = scavTrap;
	return ;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
	this->name = scavTrap.name;
	this->attackDamage = scavTrap.attackDamage;
	this->hitPoints = scavTrap.hitPoints;
	this->energyPoints = scavTrap.energyPoints;
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	if (this->hitPoints <= 0)
	{
		std::cout << this->name << "(ScavTrap) is dead" << std::endl;
		return ;
	}
	if (this->energyPoints <= 0)
	{
		std::cout << this->name << "(ScavTrap) is out of energy and could not attack " << std::endl;
		return ;
	}
	std::cout << this->name << "(ScavTrap) fires a lasershot to " << target << " and deals " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints--;
}

void ScavTrap::guardGate()
{
    if (this->hitPoints <= 0)
	{
		std::cout << this->name << "(ScavTrap) is dead" << std::endl;
		return ;
	}
	std::cout << "ScavTrap : " << this->name << " is now in Gate keeper mode" << std::endl;
}