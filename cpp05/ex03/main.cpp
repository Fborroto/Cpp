/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:37:48 by fborroto          #+#    #+#             */
/*   Updated: 2024/07/16 01:58:52 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern	piero;
	AForm*	form[4];

	form[0] = piero.makeForm("shrubbery creation", "silvio");
	form[1] = piero.makeForm("robotomy request", "piero");
	form[2] = piero.makeForm("presidential pardon", "evocaturo");
	form[3] = piero.makeForm("presidente", "matteotti");

	Bureaucrat angela("angela", 1);
	angela.signForm(*form[0]);
	angela.executeForm(*form[0]);
	
	delete form[0];
	delete form[1];
	delete form[2];
	delete form[3];
}