/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:17:26 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/28 23:53:06 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
    ScavTrap();

    public:
    ScavTrap(std::string name);
    ~ScavTrap();
    
    ScavTrap(const ScavTrap &scavTrap);
    ScavTrap &operator=(const ScavTrap &scavTrap);
    void    attack(std::string const& target);
    void guardGate();
};

#endif