/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:41:24 by fborroto          #+#    #+#             */
/*   Updated: 2024/08/02 16:33:59 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
# include <cstdlib>

class ScalarConverter   
{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const & scalar);
        ScalarConverter &operator=(ScalarConverter const & scalar);
    public:
        ~ScalarConverter();
        static void scalarConvert(std::string input);
};

#endif