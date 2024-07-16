/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 03:13:20 by fborroto          #+#    #+#             */
/*   Updated: 2024/07/15 22:18:21 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


AForm::AForm(std::string name, int const gradeSign, int const gradeExec) : name(name), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
    if (gradeExec < 1 || gradeSign < 1)
        throw GradeTooHighException();
    if (gradeExec > 150 || gradeSign > 150)
        throw GradeTooLowException();
}

AForm::~AForm()
{

}

AForm::AForm(AForm const &form) : name(form.name), isSigned(form.isSigned), gradeSign(form.gradeSign), gradeExec(form.gradeExec)
{
}
AForm &AForm::operator=(AForm const & form)
{
    if(this == &form)
        return(*this);
    isSigned = form.isSigned;
    return(*this);
}

std::string AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int  AForm::getGradeSign() const
{
    return gradeSign;
}

int  AForm::getGradeExec() const
{
    return gradeExec;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() <= gradeSign)
        isSigned = true;
    else
    throw Bureaucrat::GradeTooLowExeption();
     
}


std::ostream &operator<<(std::ostream &output, AForm const &form)
{
	output << form.getName() << ",form grade to sign " << form.getGradeSign() << " form grade to execute :"  << form.getGradeExec() << " isSigned: " << form.getIsSigned();
	return (output);
}