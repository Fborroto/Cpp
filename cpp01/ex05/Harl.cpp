/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:16:21 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/28 04:18:46 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void    Harl::debug( void ) {
    std::cout << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void    Harl::info( void ) {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void    Harl::warning( void ) {
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming foryears whereas you started working here since last month." << std::endl;
}

void    Harl::error( void ) {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}

void    Harl::complain( std:: string level ) {

      size_t      index;
    t_func  complains[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    std::string levels[] = { "ERROR", "INFO", "WARNING", "DEBUG"};
    for(index = 0 ; index < 4 && level != levels[index]; index++) {}
    if (index < 4)
        (this->*complains[index])();
}