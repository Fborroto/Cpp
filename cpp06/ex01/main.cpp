/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:41:38 by fborroto          #+#    #+#             */
/*   Updated: 2024/07/28 06:25:05 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data;

    data.nb = 11;
    data.string = "prova";
    
	uintptr_t uintptr = Serializer::serialize(&data);
	std::cout << "Raw: " << uintptr << std::endl;
    
	Data* ptr = Serializer::deserialize(uintptr);
	std::cout << "Ptr: " << ptr << std::endl;

	std::cout << "Data: " << ptr->string << " " << ptr->nb << std::endl;

	return 0;

}