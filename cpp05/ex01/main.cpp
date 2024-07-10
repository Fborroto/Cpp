/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:37:48 by fborroto          #+#    #+#             */
/*   Updated: 2024/07/10 04:08:11 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"

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
        
        Form ilForm("ilForm", 100, 40);

        meloni.signForm(ilForm);
        

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    //fattelo da solo.
}