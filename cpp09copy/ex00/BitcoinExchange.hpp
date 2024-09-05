/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:41:24 by fborroto          #+#    #+#             */
/*   Updated: 2024/08/31 07:21:58 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <exception>
#include <algorithm>
#include <climits>
#include <string>
#include <cstdlib>
#include <iomanip> 


class BitcoinExchange
{
  private:
        std::map<std::string, float> database;

  public:  
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &src);

        void exchange(std::string file);

        class UnfilledException : public std::exception {
          public:
                char const* what()   const throw(){ return ("Not enough numbers in the container");}             
        };
        class OverflowException : public std::exception {
            public:
            char const* what() const throw(){ return ("exceeded max size of elements");}
        };
                  
};

#endif