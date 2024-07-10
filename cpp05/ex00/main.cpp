/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:37:48 by fborroto          #+#    #+#             */
/*   Updated: 2024/07/10 02:54:33 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

int main ()
{
    try
    {
        Bureaucrat meloni("Meloni", 100);
        std::cout << meloni << std::endl;
        meloni.decrementGrade();
        std::cout << meloni << std::endl;
        meloni.incrementGrade();
        std::cout << meloni << std::endl;
        Bureaucrat salvini("Salvini", 151);     
        std::cout << "qua non arriva" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    //fattelo da solo.
}