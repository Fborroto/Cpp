/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto\@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 00:10:37 by fborroto          #+#    #+#             */
/*   Updated: 2024/07/15 19:01:27 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & shrubberyCreationForm) : AForm(shrubberyCreationForm), target(shrubberyCreationForm.target)
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &shrubberyCreationForm)
{
    if(this == &shrubberyCreationForm)
    return (*this);
    AForm::operator=(shrubberyCreationForm);
    target = shrubberyCreationForm.target;
    return *this;

}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    
    if(this->getIsSigned() && executor.getGrade() <= this->getGradeExec())
    {
        std::string prova = target + "_shrubbery";
        std::ofstream file(prova.c_str());
            file << "               ,@@@@@@@,\n";
        file << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
        file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
        file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
        file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
     file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
     file << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
     file << "       |o|        | |         | |\n";
     file << "       |.|        | |         | |\n";
        file << "jgs \\\\// ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";
    }
    else
    {
        if(!this->getIsSigned())
            throw FormNotSigned();
        else
            throw Bureaucrat::GradeTooLowExeption();
    }
    
}