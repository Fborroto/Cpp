/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:00:03 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/11 18:12:50 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie{
    private :
        std::string name;
    public :
         Zombie();
        ~Zombie();
        void announce(void);
        void setZombieName(std::string);
};

Zombie* zombieHorde( int N, std::string name );

#endif