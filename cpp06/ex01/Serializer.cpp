/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:41:41 by fborroto          #+#    #+#             */
/*   Updated: 2024/08/02 17:01:23 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
    
}

Serializer::Serializer(Serializer const & serialize)
{
    *this = serialize;
}


Serializer &Serializer::operator =(Serializer const & serialize)
{
    (void)serialize;
    return *this;
}

Serializer::~Serializer()
{
    
}

uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}
