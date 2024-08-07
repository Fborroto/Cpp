/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:37:48 by fborroto          #+#    #+#             */
/*   Updated: 2024/07/16 01:50:24 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try {
		Bureaucrat b1("ranpo", 137);
		Bureaucrat v1("enemies", 150);
		ShrubberyCreationForm f1("shrubbery");
		b1.signForm(f1);
		b1.executeForm(f1);
		v1.executeForm(f1);
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat b2("fursini", 45);
		Bureaucrat v2("the cattivo", 150);
		RobotomyRequestForm f2("robotomy");
		b2.signForm(f2);
		b2.executeForm(f2);
		v2.executeForm(f2);
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat b3("lobotomia", 5);
		Bureaucrat v3("cervelli", 150);
		PresidentialPardonForm f3("presidente");
		b3.signForm(f3);
		b3.executeForm(f3);
		v3.executeForm(f3);
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}