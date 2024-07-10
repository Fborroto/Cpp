/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 03:13:20 by fborroto          #+#    #+#             */
/*   Updated: 2024/07/10 21:38:14 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form(std::string name, int const gradeSign, int const gradeExec) : name(name), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
    if (gradeExec < 1 || gradeSign < 1)
        throw Bureaucrat::GradeTooHighException();
    if (gradeExec > 150 || gradeSign > 150)
        throw Bureaucrat::GradeTooLowExeption();
}

Form::~Form()
{
}

Form::Form(Form const &form) : name(form.name), isSigned(form.isSigned), gradeSign(form.gradeSign), gradeExec(form.gradeExec)
{
}
Form &Form::operator=(Form const & form)
{
    if(this == &form)
        return(*this);
    isSigned = form.isSigned;
    return(*this);
}

std::string Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int  Form::getGradeSign() const
{
    return gradeSign;
}

int  Form::getGradeExec() const
{
    return gradeExec;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() <= gradeSign)
        isSigned = true;
    else
    throw Bureaucrat::GradeTooLowExeption();
     
}


std::ostream &operator<<(std::ostream &output, Form const &form)
{
	output << form.getName() << ",form grade to sign " << form.getGradeSign() << " form grade to execute :"  << form.getGradeExec() << " isSigned: " << form.getIsSigned();
	return (output);
}