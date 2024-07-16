/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 00:10:23 by fborroto          #+#    #+#             */
/*   Updated: 2024/07/16 00:58:09 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 72, 45), target(target)
{
}
PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & presidentialPardonForm) : AForm(presidentialPardonForm), target(presidentialPardonForm.target)
{

}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &presidentialPardonForm)
{
    if(this == &presidentialPardonForm)
    return (*this);
    AForm::operator=(presidentialPardonForm);
    target = presidentialPardonForm.target;
    return *this;

}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
      if(this->getIsSigned() && executor.getGrade() <= this->getGradeExec())
    {
        std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
    else
    {
        if(!this->getIsSigned())
            throw FormNotSigned();
        else
            throw Bureaucrat::GradeTooLowExeption();
}
}