/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 00:10:29 by fborroto          #+#    #+#             */
/*   Updated: 2024/07/16 00:58:19 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}
RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & robotomyRequestForm) : AForm(robotomyRequestForm), target(robotomyRequestForm.target)
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &robotomyRequestForm)
{
    if(this == &robotomyRequestForm)
    return (*this);
    AForm::operator=(robotomyRequestForm);
    target = robotomyRequestForm.target;
    return *this;

}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
      if(this->getIsSigned() && executor.getGrade() <= this->getGradeExec())
    {
        std::cout << "LOUD DRILLING NOISES" << std::endl;
        srand(time(NULL));
        if (rand() % 2 == 0)
		std::cout << target << " robotomization successfull" << std::endl;
	else
		std::cout << target << " robotomization failed" << std::endl;
    }
    else
    {
        if(!this->getIsSigned())
            throw FormNotSigned();
        else
            throw Bureaucrat::GradeTooLowExeption();
}
}


