/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:38:17 by fborroto          #+#    #+#             */
/*   Updated: 2024/07/15 22:24:57 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AForm_HPP
#define AForm_HPP
#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class AForm
{
    private:
        std::string const name;
        bool isSigned;
        int const gradeSign;
        int const gradeExec;
    public:
    AForm(std::string name, int const gradeSign, int const gradeExec);
    virtual ~AForm();
    AForm(AForm const &AForm);
    AForm &operator=(AForm const &AForm);
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeSign() const;
    int getGradeExec() const;
        class  GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Grade too high exception");
                }
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
            virtual const char * what() const throw()
            {
                return("Grade to sign too low exception");
            }            
        };

             class GradeExecTooLowException : public std::exception
        {
            public:
            virtual const char * what() const throw()
            {
                return("Grade to execute too low exception");
            }            
        };
              class FormNotSigned : public std::exception
        {
            public:
            virtual const char * what() const throw()
            {
                return("Form is not signed exception");
            }            
        };
    void beSigned(Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream & output, AForm const &AForm);
#endif