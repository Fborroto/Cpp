/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 05:01:57 by fborroto          #+#    #+#             */
/*   Updated: 2024/07/28 05:27:54 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
       
    if(argc != 2)
    {
        std::cerr << "Invalid arguments\n";
        return 1;
    }
    ScalarConverter::scalarConvert(argv[1]);
    return 0;
}