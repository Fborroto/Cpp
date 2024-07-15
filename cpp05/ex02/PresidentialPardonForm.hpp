/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 00:10:31 by fborroto          #+#    #+#             */
/*   Updated: 2024/07/14 20:18:36 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "Bureaucrat.hpp"


class PresidentialPardonForm : public AForm
{
    private:
        std::string target;

            
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const &presidentialPardonForm);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &presidentialPardonForm);
        ~PresidentialPardonForm();

        void execute(Bureaucrat &executor) const;
};

#endif
