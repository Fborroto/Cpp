/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:04:59 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/28 23:03:40 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_CPP

#include <iostream>
#include <string>

class ClapTrap
{
    private:
        std::string name;
        int hitPoints;
        int energyPoints;
        int attackDamage;
        ClapTrap();
                    
    public :
        ClapTrap(std::string name);
        ~ClapTrap();
        
        ClapTrap(const ClapTrap &clapTrap);
        ClapTrap &operator=(const ClapTrap &ClapTrap);  
            
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif