/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:00:03 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/11 18:02:32 by fborroto         ###   ########.fr       */
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
         Zombie(std::string);
        ~Zombie();
        void announce(void);
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif