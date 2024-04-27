/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:05:29 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/27 22:42:01 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    
    std::string input;
    Harl        harl;

    while (true)
    {
        std::cout << "Enter a valid input: ";
        std::cin >> input;
        harl.complain(input);
        if(input.compare("exit") == 0)
            break;
    }

    return 0;
}