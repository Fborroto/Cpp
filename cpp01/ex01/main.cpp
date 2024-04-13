/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:57:44 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/11 18:20:59 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(void)
{
    int numberOfZombies = 5;
    Zombie *horde = zombieHorde(numberOfZombies, "franco");
    for(int i = 0; i < numberOfZombies; i++)
        horde[i].announce();
    delete [] horde;
}