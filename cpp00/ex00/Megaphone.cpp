/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:51:15 by fborroto          #+#    #+#             */
/*   Updated: 2023/11/28 14:51:15 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string StringToUpper(char *str)
{
    for (size_t i = 0; str[i]; i++)
        str[i] = toupper(str[i]);
    return (str);
}

int main(int argc, char **argv)
{
    if (argc <= 1)
        std::cout << "* LOUD AND UNBERABLE FEEDBACK NOISE *\n";
    else
    {
        for (size_t i = 1; i < argc; i++)
            std::cout << StringToUpper(argv[i]);
        std::cout << "\n";
    }
}