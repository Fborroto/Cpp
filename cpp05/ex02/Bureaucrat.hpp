/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:40:16 by fborroto          #+#    #+#             */
/*   Updated: 2024/07/14 20:16:21 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

class AForm;

class Bureaucrat
{
    private:
        std::string const name;
        int grade;
    public:
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(Bureaucrat const &bureaucrat);
        Bureaucrat &  operator=(Bureaucrat const &bureaucrat);
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &AForm);
        void executeForm(AForm const & form);
        class  GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {   
                    return ("Grade too high exception");
                }
        };
        
        class GradeTooLowExeption : public std::exception
        {
            public:
            virtual const char * what() const throw()
            {
                return("Grade too low exception");
            }            
        };
};

std::ostream &operator<<(std::ostream & output, Bureaucrat const &bureaucrat);

#endif



