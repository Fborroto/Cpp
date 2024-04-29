/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:04:57 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/29 05:10:36 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(100), energyPoints(50), attackDamage(20)
{
    std::cout << "(ClapTrap) Constructor Call for : " << name << std::endl;
}      

ClapTrap::~ClapTrap()
{
    std::cout << "(ClapTrap) Destructor  Call for : " << name << std::endl;
    return;
}
ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
    std::cout << "(ClapTrap) CopyConstructor Call" << std::endl;
    *this = clapTrap;
    return;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
    this->name = clapTrap.name; 
    this->attackDamage = clapTrap.attackDamage;
    this->hitPoints = clapTrap.hitPoints;
    this->energyPoints = clapTrap.energyPoints;
    return  *this;
}  

void ClapTrap::attack(const std::string &target)
{
    if(this->hitPoints <= 0)
    {
        std::cout << this->name << "(ClapTrap) is dead"<< std::endl;
        return;
    }
    if(this->energyPoints <= 0)
    {
        std::cout << this->name << "(ClapTrap) is out of energy and could not attack " << std::endl;
        return;
    }
    std::cout << this->name << "(ClapTrap) fires a blastshot to " << target << " and deals " << this->attackDamage << " points of damage!" << std::endl;
    this->energyPoints--;
}

void    ClapTrap::takeDamage( unsigned int amount )
{
    this->hitPoints -= amount;
    if (this->hitPoints <= 0)
    {
        std::cout << this->name << " took too much damage and died!" << std::endl;
        return;
    }
    std::cout << this->name << " takes " << amount << " points of damage!" << std::endl;
}

void    ClapTrap::beRepaired( unsigned int amount )
{
    if(this->hitPoints <= 0)
    {
        std::cout << this->name << " is dead"<< std::endl;
        return;
    }
    if (this->energyPoints <= 0)
    {
        std::cout << this->name << " is out of energy and could not repair himself!" << std::endl;
        return;
    }
    std::cout << this->name<< " repairs itself for " << amount << " hit points!" << std::endl;
    this->energyPoints -= 1;
    this->hitPoints += amount;
}