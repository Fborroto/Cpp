/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:41:44 by fborroto          #+#    #+#             */
/*   Updated: 2024/08/02 16:48:25 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
#include <stdint.h>
#include <string>

struct Data
{
    int nb;
    std::string string;
};

class Serializer
{
	private:
		Serializer();
        Serializer(Serializer const & serialize);
        Serializer &operator=(Serializer const & serialize);

	public:
		~Serializer();
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};


#endif