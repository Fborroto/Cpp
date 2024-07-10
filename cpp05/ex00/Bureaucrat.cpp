/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:40:19 by fborroto          #+#    #+#             */
/*   Updated: 2024/07/10 03:26:46 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowExeption();

}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(Bureaucrat const &bureaucrat) : name(bureaucrat.name),
	grade(bureaucrat.grade)
{
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &bureaucrat)
{
	if (this == &bureaucrat)
		return (*this);
	grade = bureaucrat.getGrade();
	return (*this);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

std::string Bureaucrat::getName() const
{
	return (name);
}

void Bureaucrat::incrementGrade()
{
	grade--;
	if (grade < 1)
		throw Bureaucrat::GradeTooLowExeption();
}

void Bureaucrat::decrementGrade()
{
	grade++;
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
}

std::ostream &operator<<(std::ostream &output, Bureaucrat const &bureaucrat)
{
	output << bureaucrat.getName() << ",bureaucrat grade " << bureaucrat.getGrade();
	return (output);
}