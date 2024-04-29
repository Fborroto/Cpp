/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:44:54 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/29 02:59:39 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	std::string name1;
	std::string name2;
	std::string name3;

	std::cout << "Create the ClapTrap" << std::endl;
	std::cin >> name1;

	std::cout << "Create the ScavTrap" << std::endl;
	std::cin >> name2;

	std::cout << "Create the FragTrap" << std::endl;
	std::cin >> name3;

	ClapTrap clapTrap1(name1);
	ScavTrap scavTrap2(name2);
	FragTrap fragTrap3(name3);

	fragTrap3.highFivesGuys();
	scavTrap2.guardGate();
	scavTrap2.attack(name1);
	scavTrap2.takeDamage(0);
	scavTrap2.beRepaired(1);

	for (int i = 0; i < 50; i++)
	{
		clapTrap1.attack(name2);
	}
	for (int i = 0; i < 50; i++)
	{
		scavTrap2.takeDamage(20);
	}
	for (int i = 0; i < 10; i++)
	{
		scavTrap2.beRepaired(1);
	}
	for (int i = 0; i < 101; i++)
	{
		fragTrap3.beRepaired(1);
	}
	clapTrap1.beRepaired(1);
}