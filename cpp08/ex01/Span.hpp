/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:41:24 by fborroto          #+#    #+#             */
/*   Updated: 2024/09/27 14:40:15 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>


class Span
{
  private:
        unsigned int N;
        std::vector<int> vector;
        
        class UnfilledException : public std::exception {
          public:
                char const* what()   const throw(){ return ("Not enough numbers in the container");}             
        };
        class OverflowException : public std::exception {
            public:
            char const* what() const throw(){ return ("exceeded max size of elements");}
        };
            
  public:  
        Span(unsigned int N);
        ~Span();
        Span(const Span &src);
        Span &operator=(const Span &src);
        void addNumber(int newNumber);
        void iterAddNumber(unsigned int size);
        int shortestSpan();
        int longestSpan();
        void print();
                     
};

#endif