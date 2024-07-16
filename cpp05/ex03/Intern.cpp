/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 01:04:46 by fborroto          #+#    #+#             */
/*   Updated: 2024/07/16 01:47:29 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    
}

Intern::~Intern()
{
    
}

Intern::Intern(Intern const & intern)
{
    (void)intern;
}

Intern & Intern::operator=(Intern const & intern)
{
    (void)intern;
    return (*this);
}

AForm * Intern::makeForm(std::string name, std::string target)
{
    std::string availableNames[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    int index = -1;

    for(int i = 0; i < 3; i++)
    {
        if(availableNames[i] == name)
            index = i;
    }
    AForm *form;
    switch(index)
    {
        case -1:
            std::cout << "Form not found" << std::endl;
			    return NULL;
        case 0:
            form = new RobotomyRequestForm(target);
            break ;
        case 1:
            form = new PresidentialPardonForm(target);
            break;
        case 2:
            form = new ShrubberyCreationForm(target);
            break;
    }
    std::cout << "Intern creates " << form->getName() << std::endl;
    return form;
}



