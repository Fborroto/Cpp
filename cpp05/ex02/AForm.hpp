/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:38:17 by fborroto          #+#    #+#             */
/*   Updated: 2024/07/10 21:38:25 by fborroto         ###   ########.fr       */
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
    ~AForm();
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

std::ostream &operator<<(std::ostream & output, AForm const &AForm);
#endif