/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 00:10:34 by fborroto          #+#    #+#             */
/*   Updated: 2024/07/14 20:17:37 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "Bureaucrat.hpp"


class RobotomyRequestForm : public AForm
{
    private:
        std::string target;

            
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const &robotomyRequestForm);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &robotomyRequestForm);
        ~RobotomyRequestForm();

        void execute(Bureaucrat &executor) const;
};

#endif