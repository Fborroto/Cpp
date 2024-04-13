/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:57:44 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/13 01:35:59 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Weapon.hpp"

int main(void)
{
    std::string string = "HI THIS IS BRAIN";
    std::string *ptr = &string;
    std::string &ref = string;

    std::cout << string << " address: " << &string << std::endl;
    std::cout << *ptr << " address: " << ptr << std::endl;
    std::cout << ref << " address: " << &ref << std::endl;
}