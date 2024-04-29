/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:01:57 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/28 23:10:56 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::string name1;
	std::string name2;

	std::cout << "Create the first ClapTrap" << std::endl;
	std::cin >> name1;

	std::cout << "Create the second ClapTrap" << std::endl;
	std::cin >> name2;

	ClapTrap clapTrap1(name1);
	ClapTrap clapTrap2(name2);


	clapTrap1.attack(name2);
	clapTrap2.takeDamage(0);
	clapTrap2.beRepaired(1);

    for(int i = 0; i < 10; i ++)
    {
        clapTrap1.attack(name2);
    }
        for(int i = 0; i < 10; i ++)
    {
        clapTrap1.takeDamage(1);
    }
           for(int i = 0; i < 10; i ++)
    {
        clapTrap2.beRepaired(1);
    }
    clapTrap1.beRepaired(1);
}