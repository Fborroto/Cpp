/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 00:10:42 by fborroto          #+#    #+#             */
/*   Updated: 2024/07/15 22:30:42 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include <fstream>
#include <string>


class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;

            
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const &ShrubberyCreationForm);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &ShrubberyCreationForm);
        virtual ~ShrubberyCreationForm();

        void execute(Bureaucrat const &executor) const;
};

#endif