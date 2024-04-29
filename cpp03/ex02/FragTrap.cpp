/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:15:50 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/29 05:11:16 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
	std::cout << "(FragTrap) Constructor Call for : " << name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "(FragTrap) Destructor  Call for : " << name << std::endl;
	return ;
}
FragTrap::FragTrap(const FragTrap &fragTrap) :  ClapTrap(fragTrap.name)
{
	std::cout << "(FragTrap)CopyConstructor Call" << std::endl;
	*this = fragTrap;
	return ;
}
FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
	this->name = fragTrap.name;
	this->attackDamage = fragTrap.attackDamage;
	this->hitPoints = fragTrap.hitPoints;
	this->energyPoints = fragTrap.energyPoints;
	return (*this);
}

  void FragTrap::highFivesGuys(void)
  {
        if (this->hitPoints <= 0)
	{
		std::cout << this->name << "(FragTrap) is dead" << std::endl;
		return ;
	}
	std::cout << "FragTrap : " << this->name << " is requesting an high five" << std::endl;
  }
