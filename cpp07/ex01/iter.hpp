/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:41:24 by fborroto          #+#    #+#             */
/*   Updated: 2024/08/02 06:05:14 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void iter(T* address, size_t size, void (*f)(T&))
{
    for (size_t i = 0; i < size; i++)
    {
        f(address[i]);
    }
}

template <typename T>
void printElement(T & test)
{
    std::cout << test << std::endl;
}

#endif