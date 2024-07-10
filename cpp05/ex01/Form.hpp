/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:58:17 by fborroto          #+#    #+#             */
/*   Updated: 2024/07/10 04:06:09 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class Form
{
    private:
        std::string const name;
        bool isSigned;
        int const gradeSign;
        int const gradeExec;
    public:
    Form(std::string name, int const gradeSign, int const gradeExec);
    ~Form();
    Form(Form const &form);
    Form &operator=(Form const &form);
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
        
        class GradeTooLowExeption : public std::exception
        {
            public:
            virtual const char * what() const throw()
            {
                return("Grade too low exception");
            }            
        };
    void beSigned(Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream & output, Form const &form);
#endif