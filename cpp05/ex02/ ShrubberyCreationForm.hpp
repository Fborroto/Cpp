/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ShrubberyCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 00:10:42 by fborroto          #+#    #+#             */
/*   Updated: 2024/07/14 20:16:04 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRYCREATIONFORM_HPP
#define SHRUBERRYCREATIONFORM_HPP
#include "Bureaucrat.hpp"


class ShrubberyCreatingForm : public AForm
{
    private:
        std::string target;

            
    public:
        ShrubberyCreatingForm(std::string target);
        ShrubberyCreatingForm(ShrubberyCreatingForm const &shrubberyCreatingForm);
        ShrubberyCreatingForm &operator=(ShrubberyCreatingForm const &shrubberyCreatingForm);
        ~ShrubberyCreatingForm();

        void execute(Bureaucrat &executor) const;
};

#endif