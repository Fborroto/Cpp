/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:41:24 by fborroto          #+#    #+#             */
/*   Updated: 2024/08/02 05:37:56 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;    
}

template <typename T>
T min(T first, T second)
{
    if (first == second)
     return second;
    return first < second ? first : second;
}

template <typename T>
T max(T first, T second)
{
    if (first == second)
     return second;
    return first > second ? first : second;
}
#endif