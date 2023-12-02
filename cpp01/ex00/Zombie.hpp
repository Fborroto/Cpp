/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:00:03 by fborroto          #+#    #+#             */
/*   Updated: 2023/12/02 17:18:56 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include  <iostream>
# include  <stdlib.h>

class Zombie
{
    private:
    std::string name;
    public:
    void announce(void);
    ~Zombie();
};

#endif
