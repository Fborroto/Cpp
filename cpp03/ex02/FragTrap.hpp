/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:15:53 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/29 03:01:02 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
    private:
    FragTrap();

    public:
    FragTrap(std::string name);
    ~FragTrap();
    
    FragTrap(const FragTrap &scavTrap);
    FragTrap &operator=(const FragTrap &scavTrap);
    void highFivesGuys(void);

};

#endif